#pragma once
#ifndef CTAMANAGER_H
#define CTAMANAGER_H

#include"json11.hpp"
#include"utils.hpp"
#include"../event_engine/eventengine.h"
#include"../risk_manager/riskmanager.h"
#include"../cta_strategy/StrategyTemplate.h"
#include"../gateway/gatewaymanager.h"
#include"../portfolio.h"
#include<functional>
#include<cstdio>
//#include <windows.h>
//#include<minwindef.h>
#include"MongoCxx.h"
#include"../include/libmongoc-1.0/mongoc.h"
#include"../include/libbson-1.0/bson.h"
//#include "stdafx.h"

//#include "second.h"
#define CTAORDER_BUY "ctaorderbuy"
#define CTAORDER_SELL "ctaordersell"
#define CTAORDER_SHORT "ctaordershort"
#define CTAORDER_COVER "ctaordercover"
//class EventEngine;
//class Gatewaymanager;
//class riskmanager;
class StrategyTemplate;
//class mongoc_uri_t;
//class mongoc_client_pool_t;
class Portfolio;

//typedef StrategyTemplate* (*Dllfun)(CTAmanager*);
//typedef int(*Release)();
/*******************************************/
class PositionBuffer//��������ֲ�
{
public:
	std::string symbol;//��Լ

	//��ͷ
	double longposition = 0;
	double longtodayposition = 0;
	double longydposition = 0;
	//��ͷ
	double shortposition = 0;
	double shorttodayposition = 0;
	double shortydposition = 0;
};

class CTAmanager 
{
public:
	//CTA������
	CTAmanager(Gatewaymanager* gatewaymanager, EventEngine* eventengine, riskmanager* riskmanager);
	~CTAmanager();

	//�������躯��
	std::vector<std::string> sendOrder(std::string symbol, std::string orderType, double price, double volume, StrategyTemplate* Strategy);
	void cancelOrder(std::string orderID, std::string gatewayname);
	void writeCtaLog(std::string msg, std::string gatewayname);
	void PutEvent(std::shared_ptr<Event>e);
	std::vector<TickData> loadTick(std::string tickDbName, std::string symbol, int days);
	std::vector<BarData> loadBar(std::string BarDbName, std::string symbol, int days);


	//������������躯��
	void loadStrategy();																//���ز���
	void initStrategy(std::string name);												//��ʼ��
	void startStrategy(std::string name);												//��ʼ����
	void stopStrategy(std::string name);												//ֹͣ����
	void initallStrategy();															//��ʼ�����в���
	void startallStrategy();															//�������в���
	void stopallStrategy();															//ֹͣ���в���
	void changesupposedpos(std::string name, std::string symbol, double pos);			//ͨ�����������Ƴֲ�

	//��������
	void savetraderecord(std::string strategyname, std::shared_ptr<Event_Trade>etrade);
private:
	EventEngine* m_eventengine;
	Gatewaymanager* m_gatewaymanager;
	riskmanager* m_riskmanager;

	bool is_LoadStrategy;

	//����  ��   ������   ���̰߳�ȫ
	//key ��OrderID  value �ǲ��Զ��� ��;��Ϊ�˱�֤�������������Է���ȥ��  �ɽ��ر�����ֲ���ȷ���ض�Ӧ�Ĳ����ϣ��Է�������Խ���ͬһ����Լ����BUG
	std::map<std::string, StrategyTemplate*>m_orderStrategymap;		std::mutex m_orderStrategymtx;
	//key ��Լ�� value �ֲֶ���   ��������ÿһ����Լ�Ľ������Ƕ���
	std::map<std::string, PositionBuffer>m_symbolpositionbuffer;	std::mutex m_symbolpositionmtx;

	//key ��Լ����value ����ָ��(ʵ��)vector  �����Ѳ�ͬ�ĺ�Լtick���͵�ÿһ�����Զ���
	std::map<std::string, std::vector<StrategyTemplate*>>m_tickstrategymap;	std::mutex m_tickstrategymtx;
	//key ������, value Ϊ����ָ��    �����ѽ���ѡ�еĲ����� ��Ӧ�ĵĲ��Զ�������
	std::map<std::string, StrategyTemplate*>m_strategymap;			std::mutex m_strategymtx;

	//��������
	void procecssTickEvent(std::shared_ptr<Event>e);
	void processOrderEvent(std::shared_ptr<Event>e);
	void processTradeEvent(std::shared_ptr<Event>e);
	void processPositionEvent(std::shared_ptr<Event>e);

	//ע�ᴦ������
	void registerEvent();

	//DLL�洢
	std::map<std::string, HINSTANCE>dllmap;//��Ų���dll����

	//�Զ�����
	void showLog(std::shared_ptr<Event>e);
	std::atomic_bool m_connectstatus;
	void autoConnect(std::shared_ptr<Event>e);

	//MONGOC �̳߳�
	mongoc_uri_t* m_uri;
public:
	mongoc_client_pool_t* m_pool;

	//portfolio
	Portfolio* m_portfolio;
};
#endif