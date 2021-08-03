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
			//����򲻿��ļ�
			std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
			e->msg = "�޷���ȡ���ط��������ļ�";
			e->gatewayname = "riskmanager";
			this->onLog(e);
			return;
		}
		std::string line;
		std::map<std::string, std::string>configmap;
		while (!f.eof())
		{
			getline(f, line);
			std::string::size_type pos = line.find("=");//���յȺŷָ�
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
		e->msg = "�޷���ȡ���ձ��������ļ�";
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
	//���orderSizeLimit=0��Ϊ�����ƴ�������������������
	if (req.volume > orderSizeLimit&& orderSizeLimit!=0)
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "����ί������"+ Utils::doubletostring(req.volume) + "��������" + Utils::doubletostring(orderSizeLimit);
		e->gatewayname = "riskmanager";
		this->onLog(e);
		return false;
	}

	if (tradeCount >= tradeLimit && tradeLimit!=0)
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "�����ܳɽ�����" + Utils::doubletostring(tradeCount) + "��������" + Utils::doubletostring(tradeLimit);
		e->gatewayname = "riskmanager";
		this->onLog(e);
		return false;
	}

	if (orderFlowCount >= orderFlowLimit && orderFlowLimit!=0)
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "ί��������" + Utils::doubletostring(orderFlowCount) + "��������" + Utils::doubletostring(orderFlowLimit);
		e->gatewayname = "riskmanager";
		this->onLog(e);
		return false;
	}

	////��Լ�������ޣ�������������ĵ���Լ�����������ޣ�ÿ����Լ����ͳ�ƣ�
	std::lock_guard<std::mutex>lck(orderCancelMapMtx);
	if (orderCancelMap.find(req.symbol) != orderCancelMap.end())
	{
		if (orderCancelMap[req.symbol] >= orderCancelLimit && orderCancelLimit!=0)
		{
			std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
			e->msg = "����" + req.symbol + "��������" + Utils::doubletostring(orderCancelMap[req.symbol]) 
													+ "��������" + Utils::doubletostring(orderCancelLimit);
			e->gatewayname = "riskmanager";
			this->onLog(e);
			return false;
		}
	}
	//workingOrderLimit�ί�����ޣ�����Ĵ��ڻ״̬���ύ�С�δ�ɽ������ֳɽ������ί������
	//��д


	orderFlowCount += 1;//������ж϶�ͨ����ί����������һ
	
	return true;

}

void RiskManagerEngine::clearOrderFlowCount()
{
	orderFlowCount = 0;
	std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
	e->msg = "������ؼ���";
	e->gatewayname = "riskmanager";
	this->onLog(e);
}

void RiskManagerEngine::clearTradeCount()
{
	tradeCount = 0;
	orderFlowCount = 0;
	std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
	e->msg = "����ܳɽ�����";
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
		e->msg = "���չ����ܴ�";
		e->gatewayname = "riskmanager";
		this->onLog(e);
		active = !active;
		return true;
	}
	else
	{
		std::shared_ptr<Event_Log>e = std::make_shared<Event_Log>();
		e->msg = "���չ�����ֹͣ";
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
	e->msg = "��ز����ѱ���";
	e->gatewayname = "riskmanager";
	this->onLog(e);
	
}