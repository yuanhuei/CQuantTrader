#pragma once
#ifndef RFC_FRAME_H
#define RFC_FRAME_H
#include<string>
#include<zmq.hpp>
#include<zmq_addon.hpp>

#include<map>
#include<thread>
#include<mutex>
#include"RpcTestDialog.h"
#include"../qcstructs.h"
#include"network.h"

void generate_certificates(std::string strname);

class RpcServer
{
public:
	RpcServer(RpcTestDialog * pRpctestDialog);
	~RpcServer();

	bool isActive();
	void start(std::string rep_address, std::string pub_address);
	void stop();
	void join();
	void run();
	void publish(std::string strTopic, NetworkTool::ServerMessage cmessage= NetworkTool::ServerMessage());
	void fun_register();
	void outputString(std::string strText);


private:
	//# Save functions dict : key is fuction name, value is fuction object
	std::map < std::string,int >	m_functions;

	//# Zmq port related
	zmq::context_t m_zmqcontext;

	//# Reply socket(Request每reply pattern)
	zmq::socket_t* m_socket_rep;
	
	//# Publish socket(Publish每subscribe pattern)
	zmq::socket_t* m_socket_pub;

		//# Worker thread related
	bool m_active =false;
	std::thread  m_thread; // m_thread: threading.Thread = None          # RpcServer thread
	std::mutex m_threadMutex;
	RpcTestDialog* m_rpctestDialog;

};
class RpcGateway;

class RpcClient
{
public:
	RpcClient(RpcTestDialog* pRpctestDialog=NULL);
	RpcClient(RpcGateway *pRpcGateaway = NULL);
	~RpcClient();

	void start(std::string req_address, std::string sub_address);// std::string rep_address, std::string pub_address, std::string str_username, std::string str_password, std::string server_secretkey_path);
	void stop();
	void join();
	void run();
	void callback(std::string topic, NetworkTool::ServerMessage sMessage);
	void subscribe_topic(std::string strTopic);
	void on_disconnected();
	std::string sendRequest(std::string strReq);
	void call_server(std::vector<NetworkTool::ClientMessage> v_para);



private:
	void outputString(std::string strText);
	//# Save functions dict : key is fuction name, value is fuction object
	std::map < std::string, int >	m_functions;
	//# Zmq port related
	zmq::context_t m_zmqcontext;

	//# Reply socket(Request每reply pattern)
	zmq::socket_t* m_socket_req;

	//# Publish socket(Publish每subscribe pattern)
	zmq::socket_t* m_socket_sub;

	//# Worker thread related
	bool m_active = false;
	std::thread  m_thread; // m_thread: threading.Thread = None          # RpcServer thread
	std::mutex m_threadMutex;

	RpcTestDialog* m_rpctestDialog;
	RpcGateway* m_RpcGateway;

};
#endif // !RFC_FRAME_H
