#pragma once
#ifndef RFC_FRAME_H
#define RFC_FRAME_H
#include<string>
#include<zmq.hpp>
#include<zmq_addon.hpp>
#include<nanomsg/reqrep.h>
#include<map>
#include<thread>

void generate_certificates(std::string strname);

class RpcServer
{
public:
	RpcServer();
	~RpcServer();

	bool isActive();
	void start(std::string rep_address, std::string pub_address, std::string str_username, std::string str_password, std::string server_secretkey_path);
	void stop();
	void join();
	void run();
	void publish();
	void fun_register();



private:
	//# Save functions dict : key is fuction name, value is fuction object
	std::map < std::string,int >	m_functions;// : Dict[str, Any] = {}

	//# Zmq port related
	zmq::context_t m_zmqcontext;

	//# Reply socket(Request¨Creply pattern)
	zmq::socket_t* m_socket_rep; //zmq.Socket = self.__context.socket(zmq.REP)
	
	//# Publish socket(Publish¨Csubscribe pattern)
		
	zmq::socket_t* m_socket_pub;// zmq.Socket = self.__context.socket(zmq.PUB)

		//# Worker thread related
	bool m_active =false;//                     # RpcServer status
	std::thread  m_thread; // m_thread: threading.Thread = None          # RpcServer thread
	//std::thread m_lock: threading.Lock = threading.Lock()

	//# Authenticator used to ensure data security
	//m_authenticator: ThreadAuthenticator = None

};
class RpcClient
{
public:
	RpcClient();
	~RpcClient();

	void start();// std::string rep_address, std::string pub_address, std::string str_username, std::string str_password, std::string server_secretkey_path);
	void stop();
	void join();
	void run();
	void callback();
	void subscribe_topic();
	void on_disconnected();


private:


};
#endif // !RFC_FRAME_H
