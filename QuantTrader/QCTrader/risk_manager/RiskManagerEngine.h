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
��ǰ���ģ�鸺����ί��ͨ������API�ӿڷ���ǰ�������״̬�Ƿ���ϸ��ַ�ع���
��ع�������������ء��µ��������ί�С����������ȣ��������£�

ί��������أ�

ί���������ޣ�����ʱ�䴰���������������ί�б���

ί��������գ�ÿ����������������ͳ�Ƶ�ί�б���

����ί�����ޣ�ÿһ��ί�����������µ���

�ܳɽ����ޣ������������������ܳɽ�������ע�ⲻ��ί�б�����

�ί�����ޣ�����Ĵ��ڻ״̬���ύ�С�δ�ɽ������ֳɽ������ί������

��Լ�������ޣ�������������ĵ���Լ�����������ޣ�ÿ����Լ����ͳ�ƣ�

�Ƽ�ÿ���������Զ�����ǰ������ǰ��أ��Լ��ÿһ�ʷ�����ί���Ƿ���Ϸ��Ҫ��
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
	std::atomic_int orderFlowLimit;//ί���������ޣ�����ʱ�䴰���������������ί�б���

	std::atomic_int orderFlowClear;//ί��������գ�ÿ����������������ͳ�Ƶ�ί�б���
	std::atomic_int orderFlowTimer;

	std::atomic_int orderSizeLimit;//����ί�����ޣ�ÿһ��ί�����������µ���


	std::atomic_int tradeLimit;//�ܳɽ����ޣ������������������ܳɽ�������ע�ⲻ��ί�б�����

	std::atomic_int orderCancelLimit;//��Լ�������ޣ�������������ĵ���Լ�����������ޣ�ÿ����Լ����ͳ�ƣ�
	std::map<std::string, int>orderCancelMap;			std::mutex orderCancelMapMtx;

	std::atomic_int workingOrderLimit;//�ί�����ޣ�����Ĵ��ڻ״̬���ύ�С�δ�ɽ������ֳɽ������ί������

private:
	EventEngine* eventengine_ptr;
	std::atomic_int orderFlowCount;
	std::atomic_int tradeCount;


};
#endif