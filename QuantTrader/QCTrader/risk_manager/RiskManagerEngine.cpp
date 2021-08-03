#include"RiskManagerEngine.h"
#include"../event_engine/eventengine.h"
#include"utils.hpp"
#include<io.h>
#include<direct.h>
#include<fstream>
#include"../qcstructs.h"

RiskManagerEngine::RiskManagerEngine(EventEngine* eventengine)
{
	eventengine_ptr = eventengine;
	active = false;
	orderFlowLimit = 0;
	orderFlowCount = 0;
	orderFlowClear = 0;
	orderFlowTimer = 0;
	orderSizeLimit = 0;
	tradeCount = 0;
	tradeLimit = 0;
	orderCancelLimit=0;
	workingOrderLimit = 0;
	loadSetting();
	registerEvent();
}
RiskManagerEngine::~RiskManagerEngine() {}

void RiskManagerEngine::loadSetting()
{
	if (_access("./conf", 0) != -1)
	{
		std::fstream f;
		f.open("./conf/risk_config");
		if (!f.is_open())
		{
			//如果打不开文件
			std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
			e->msg = "无法读取本地风险配置文件";
			e->gatewayname = "riskmanager";
			this->onLog(e);
			return;
		}
		std::string line;
		std::map<std::string, std::string>configmap;
		while (!f.eof())
		{
			getline(f, line);
			std::string::size_type pos = line.find("=");//按照等号分隔
			configmap.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1, line.size() - 1)));
		}
		active = Utils::stringtobool(configmap["active"]);

		orderFlowLimit = atoi(configmap["orderFlowLimit"].c_str());
		orderFlowClear = atoi(configmap["orderFlowClear"].c_str());
		orderSizeLimit = atoi(configmap["orderSizeLimit"].c_str());
		tradeLimit = atoi(configmap["tradeLimit"].c_str());
		workingOrderLimit = atoi(configmap["workingOrderLimit"].c_str());
		orderCancelLimit = atoi(configmap["orderCancelLimit"].c_str());
	}
	else
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "无法读取风险本地配置文件";
		e->gatewayname = "riskmanager";
		this->onLog(e);
	}
}

void RiskManagerEngine::onLog(std::shared_ptr<Event>e)
{
	eventengine_ptr->Put(e);
}

void RiskManagerEngine::registerEvent()
{
	eventengine_ptr->RegEvent(EVENT_TRADE, std::bind(&RiskManagerEngine::updateTrade, this, std::placeholders::_1));
	eventengine_ptr->RegEvent(EVENT_ORDER, std::bind(&RiskManagerEngine::updateOrder, this, std::placeholders::_1));
	eventengine_ptr->RegEvent(EVENT_TIMER, std::bind(&RiskManagerEngine::updateTimer, this, std::placeholders::_1));
}

void RiskManagerEngine::updateTrade(std::shared_ptr<Event>e)
{
	std::shared_ptr<Event_Trade> etrade = std::static_pointer_cast<Event_Trade>(e);
	tradeCount += etrade->volume;
}

void RiskManagerEngine::updateOrder(std::shared_ptr<Event>e)
{
	std::shared_ptr<Event_Order> eorder = std::static_pointer_cast<Event_Order>(e);
	if (eorder->status != STATUS_CANCELLED)
	{
		return;
	}
	std::lock_guard<std::mutex>lck(orderCancelMapMtx);
	if (orderCancelMap.find(eorder->symbol) == orderCancelMap.end())
	{
		orderCancelMap.insert(std::pair<std::string, int>(eorder->symbol, 1));
	}
	else
	{
		orderCancelMap[eorder->symbol] += 1;
	}
}

void RiskManagerEngine::updateTimer(std::shared_ptr<Event>e)
{
	orderFlowTimer += 1;

	if (orderFlowTimer >= orderFlowClear)
	{
		orderFlowCount = 0;
		orderFlowTimer = 0;
	}
}

bool RiskManagerEngine::checkRisk(OrderReq req)
{
	if (active == false)
	{
		return true;
	}
	//如果orderSizeLimit=0作为不限制处理，其它几个参数类似
	if (req.volume > orderSizeLimit&& orderSizeLimit!=0)
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "单笔委托数量"+ Utils::doubletostring(req.volume) + "超过限制" + Utils::doubletostring(orderSizeLimit);
		e->gatewayname = "riskmanager";
		this->onLog(e);
		return false;
	}

	if (tradeCount >= tradeLimit && tradeLimit!=0)
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "今日总成交数量" + Utils::doubletostring(tradeCount) + "超过限制" + Utils::doubletostring(tradeLimit);
		e->gatewayname = "riskmanager";
		this->onLog(e);
		return false;
	}

	if (orderFlowCount >= orderFlowLimit && orderFlowLimit!=0)
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "委托流数量" + Utils::doubletostring(orderFlowCount) + "超过限制" + Utils::doubletostring(orderFlowLimit);
		e->gatewayname = "riskmanager";
		this->onLog(e);
		return false;
	}

	////合约撤单上限：今天日内允许的单合约撤单次数上限（每个合约独立统计）
	std::lock_guard<std::mutex>lck(orderCancelMapMtx);
	if (orderCancelMap.find(req.symbol) != orderCancelMap.end())
	{
		if (orderCancelMap[req.symbol] >= orderCancelLimit && orderCancelLimit!=0)
		{
			std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
			e->msg = "当日" + req.symbol + "撤单数量" + Utils::doubletostring(orderCancelMap[req.symbol]) 
													+ "超过限制" + Utils::doubletostring(orderCancelLimit);
			e->gatewayname = "riskmanager";
			this->onLog(e);
			return false;
		}
	}
	//workingOrderLimit活动委托上限：允许的处于活动状态（提交中、未成交、部分成交）最大委托数量
	//待写


	orderFlowCount += 1;//上面的判断都通过后委托流计数加一
	
	return true;

}

void RiskManagerEngine::clearOrderFlowCount()
{
	orderFlowCount = 0;
	std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
	e->msg = "清空流控计数";
	e->gatewayname = "riskmanager";
	this->onLog(e);
}

void RiskManagerEngine::clearTradeCount()
{
	tradeCount = 0;
	orderFlowCount = 0;
	std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
	e->msg = "清空总成交计数";
	e->gatewayname = "riskmanager";
	this->onLog(e);
}

void RiskManagerEngine::setOrderFlowLimit(int n)
{
	orderFlowLimit = n;
}

void RiskManagerEngine::setOrderFlowClearTime(int n)
{
	orderFlowClear = n;
}
void RiskManagerEngine::setOrderSizeLimit(int n)
{
	orderSizeLimit = n;
}
void RiskManagerEngine::setTradeLimit(int n)
{
	tradeLimit = n;
}
void RiskManagerEngine::setWorkingOrderLimit(int n)
{
	workingOrderLimit = n;
}

void RiskManagerEngine::setOrderCancelLimit(int n)
{
	orderCancelLimit = n;
}
bool RiskManagerEngine::switchEngineStatus()
{
	

	if (active == false)
	{

		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "风险管理功能打开";
		e->gatewayname = "riskmanager";
		this->onLog(e);
		active = !active;
		return true;
	}
	else
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "风险管理功能停止";
		e->gatewayname = "riskmanager";
		this->onLog(e);
		active = !active;
		return false;
	}

}

void RiskManagerEngine::saveSetting()
{
	std::fstream f;
	std::string a = Utils::booltostring(active);
	f.open("./conf/risk_config", std::ios::out);
	f << "active=" << Utils::booltostring(active)<< std::endl;
	f << "orderFlowLimit=" << Utils::doubletostring(orderFlowLimit)<< std::endl;
	f << "orderFlowClear=" << Utils::doubletostring(orderFlowClear) << std::endl;
	f << "orderSizeLimit=" << Utils::doubletostring(orderSizeLimit) << std::endl;
	f << "tradeLimit=" << Utils::doubletostring(tradeLimit) << std::endl;
	f << "workingOrderLimit=" << Utils::doubletostring(workingOrderLimit) << std::endl;
	f << "orderCalcelLimit=" << Utils::doubletostring(orderCancelLimit) << std::endl;

	f.close();

	std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
	e->msg = "风控参数已保存";
	e->gatewayname = "riskmanager";
	this->onLog(e);
	
}