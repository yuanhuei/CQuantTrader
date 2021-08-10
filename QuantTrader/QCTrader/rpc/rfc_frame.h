#pragma once
#ifndef RFC_FRAME_H
#define RFC_FRAME_H
#include<string>
#include<zmq.hpp>
#include<zmq_addon.hpp>

#include<map>
#include<thread>
#include<mutex>

void generate_certificates(std::string strname);

class RpcServer
{
public:
	RpcServer();
	~RpcServer();

	bool isActive();
	void start(std::string rep_address, std::string pub_address);
	void stop();
	void join();
	void run();
	void publish(std::string strTopic,std::string strData);
	void fun_register();



private:
	//# Save functions dict : key is fuction name, value is fuction object
	std::map < std::string,int >	m_functions;// : Dict[str, Any] = {}

	//# Zmq port related
	zmq::context_t m_zmqcontext;

	//# Reply socket(Request�Creply pattern)
	zmq::socket_t* m_socket_rep;
	
	//# Publish socket(Publish�Csubscribe pattern)
	zmq::socket_t* m_socket_pub;

		//# Worker thread related
	bool m_active =false;//                     # RpcServer status
	std::thread  m_thread; // m_thread: threading.Thread = None          # RpcServer thread
	std::mutex m_threadMutex;


};
class RpcClient
{
public:
	RpcClient();
	~RpcClient();

	void start(std::string req_address, std::string sub_address);// std::string rep_address, std::string pub_address, std::string str_username, std::string str_password, std::string server_secretkey_path);
	void stop();
	void join();
	void run();
	void callback();
	void subscribe_topic(std::string strTopic);
	void on_disconnected();


private:
	//# Save functions dict : key is fuction name, value is fuction object
	std::map < std::string, int >	m_functions;// : Dict[str, Any] = {}

	//# Zmq port related
	zmq::context_t m_zmqcontext;

	//# Reply socket(Request�Creply pattern)
	zmq::socket_t* m_socket_req;

	//# Publish socket(Publish�Csubscribe pattern)
	zmq::socket_t* m_socket_sub;

	//# Worker thread related
	bool m_active = false;//                     # RpcServer status
	std::thread  m_thread; // m_thread: threading.Thread = None          # RpcServer thread
	std::mutex m_threadMutex;

};
#endif // !RFC_FRAME_H
