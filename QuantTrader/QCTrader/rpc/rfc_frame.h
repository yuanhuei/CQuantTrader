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
#include"rpc/network.h"
class RpcEngine;

void generate_certificates(std::string strname);

class RpcServer
{
public:
	RpcServer(RpcTestDialog * pRpctestDialog);
	RpcServer(RpcEngine* pRpcEngine);

	~RpcServer();
	inline int calculate_x_y(int x) { return x * x; };
	bool isActive();
	void start(std::string rep_address, std::string pub_address);
	void stop();
	void join();
	void run();
	void publish(std::string strTopic, NetworkTool::ServerMessage cmessage= NetworkTool::ServerMessage());
	void fun_register();
	void outputString(std::string strText);
	void call_func(NetworkTool::ClientMessage& smessage, NetworkTool::ServerMessage& returnMessage);


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
	RpcEngine* m_rpcEngine;

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
	void call_server(std::vector<NetworkTool::ClientMessage> v_para, NetworkTool::ServerMessage& returnMessage);
	template<typename T>
	void call_server(NetworkTool::MethodCallMessage<T>& v_para, NetworkTool::ServerMessage& returnMessage)
	{
		using namespace NetworkTool;
		Msgpack msgpack;
		bool result = msgpack.Pack<MethodCallMessage<T>>(v_para);

		if (result)
		{
			m_threadMutex.lock();
			result = SendMsg(&msgpack, m_socket_req, zmq::send_flags::dontwait, false);
			if (!result)
			{
				outputString("sendmsg wrong\n");
				m_threadMutex.unlock();
				return;
			}
			else
			{
				outputString("sendmsg succeed\n");
			}
			zmq_msg_t* msg = ReceiveMessage(m_socket_req);
			if (msg != NULL)
			{
				Msgpack msgpack;
				outputString("received return\n");

				BaseMessage* bmessage = msgpack.Unpack(*msg);
				CloseMsg(msg);
				if (bmessage != NULL && bmessage->Type == 2048)
				{
					returnMessage.strReturn = "NO_NULL";
					ServerMessage* smessage = static_cast<ServerMessage*>(bmessage);
					if (smessage != NULL)
					{
						if (smessage->Information[0] != "ReturnCallserver")
							outputString("sub port received:" + smessage->Information[0] + "\n");
						else
							outputString("caculation result =:" + std::to_string(smessage->iReturn) + "\n");
						returnMessage = *smessage;//殿隙硉
					}
					delete smessage;
					smessage = NULL;
					bmessage = NULL;
				}
				else
				{
					outputString("unpack failed");
				}
			}
			else
			{
				outputString("receive null msg");
			}
				
			m_threadMutex.unlock();
		}
	};
	void outputString(std::string strText);



private:
	//void outputString(std::string strText);
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
