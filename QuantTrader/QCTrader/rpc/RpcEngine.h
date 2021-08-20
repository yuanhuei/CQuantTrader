#pragma once
#ifndef RPCENGINE_H
#define RPCENGINE_H
#include<string>
#include<memory>
#include"../qcstructs.h"
#include"rpc/network.h"
class RpcServer;
class Gatewaymanager;
class MainWindow;
class EventEngine;
class MainWindow;
class RpcEngine
{
public:
	RpcEngine(MainWindow* mainwindow);
	~RpcEngine();

	void init_server();
	void load_setting();
	void save_setting();
	bool start(std::string  str_rep_address, std::string str_pub_address);
	void stop();
	void close();
	void process_event(std::shared_ptr<Event> e);
	void write_log(std::string strLog);
	void register_event();
	void call_func(std::vector<NetworkTool::ClientMessage>& vMessage, NetworkTool::ServerMessage& returnMessage);
private:
	RpcServer* m_RpcServer;
	std::string rep_address;
	std::string  pub_address;
	Gatewaymanager* m_gatewaymanager;//接口管理器
	EventEngine* m_eventengine;//事件驱动引擎
	MainWindow* m_mainwindow;
};

#endif // !RPCENGINE_H