#ifndef RISKMANAGERENGINE_H
#define RISKMANAGERENGINE_H
#include<memory>
#include<functional>
#include"utils.hpp"
#include<io.h>
#include<direct.h>
#include<fstream>
#include"../qcstructs.h"
class Event;
class EventEngine;

/*
事前风控模块负责在委托通过交易API接口发出前，检查其状态是否符合各种风控规则。
风控规则包括交易流控、下单数量、活动委托、撤单总数等，具体如下：

委托流控相关：

委托流控上限：给定时间窗口内最多允许发出的委托笔数

委托流控清空：每隔多少秒清零上述统计的委托笔数

单笔委托上限：每一笔委托允许的最大下单量

总成交上限：今天日内允许的最大总成交笔数（注意不是委托笔数）

活动委托上限：允许的处于活动状态（提交中、未成交、部分成交）最大委托数量

合约撤单上限：今天日内允许的单合约撤单次数上限（每个合约独立统计）

推荐每天在运行自动交易前启动事前风控，以检查每一笔发出的委托是否符合风控要求
*/
class RiskManagerEngine
{

public:
	RiskManagerEngine(EventEngine* eventengine);
	~RiskManagerEngine();
	void loadSetting();
	void registerEvent();
	void onLog(std::shared_ptr<Event>e);
	void updateTrade(std::shared_ptr<Event>e);
	void updateOrder(std::shared_ptr<Event>e);
	void updateTimer(std::shared_ptr<Event>e);
	bool checkRisk(OrderReq req);
	void clearOrderFlowCount();
	void clearTradeCount();
	void setOrderFlowLimit(int n);
	void setOrderFlowClearTime(int n);
	void setOrderSizeLimit(int n);
	void setTradeLimit(int n);
	void setWorkingOrderLimit(int n);
	void setOrderCancelLimit(int n);
	bool switchEngineStatus();
	void saveSetting();

	bool active;
	std::atomic_int orderFlowLimit;//委托流控上限：给定时间窗口内最多允许发出的委托笔数

	std::atomic_int orderFlowClear;//委托流控清空：每隔多少秒清零上述统计的委托笔数
	std::atomic_int orderFlowTimer;

	std::atomic_int orderSizeLimit;//单笔委托上限：每一笔委托允许的最大下单量


	std::atomic_int tradeLimit;//总成交上限：今天日内允许的最大总成交笔数（注意不是委托笔数）

	std::atomic_int orderCancelLimit;//合约撤单上限：今天日内允许的单合约撤单次数上限（每个合约独立统计）
	std::map<std::string, int>orderCancelMap;			std::mutex orderCancelMapMtx;

	std::atomic_int workingOrderLimit;//活动委托上限：允许的处于活动状态（提交中、未成交、部分成交）最大委托数量

private:
	EventEngine* eventengine_ptr;
	std::atomic_int orderFlowCount;
	std::atomic_int tradeCount;


};
#endif