#include "rfc_frame.h"

void generate_certificates(std::string strname)
{

}

RpcServer::RpcServer()
{
	m_socket_rep = new zmq::socket_t(m_zmqcontext, zmq::socket_type::rep);
	m_socket_pub = new zmq::socket_t(m_zmqcontext, zmq::socket_type::pub);


}

RpcServer::~RpcServer()
{


}

bool RpcServer::isActive()
{
	return m_active;
}

void RpcServer::start(std::string rep_address, std::string pub_address, std::string str_username,std::string str_password, std::string server_secretkey_path)
{
	if (m_active)
		return;

	m_socket_rep->bind(rep_address);
	m_socket_pub->bind(pub_address);
	m_active = true;
	m_thread = std::thread::thread(std::bind(&RpcServer::run, this));

}
void RpcServer::stop()
{
	m_active = false;

}
void RpcServer::join()
{

}
void RpcServer::run()
{

}
void RpcServer::publish()
{

}
void RpcServer::fun_register()
{

}

RpcClient::RpcClient()
{


}

RpcClient::~RpcClient()
{

}

void RpcClient::start()
{

}
void RpcClient::stop()
{

}
void RpcClient::join()
{

}
void RpcClient::run()
{

}
void RpcClient::callback()
{

}
void RpcClient::subscribe_topic()
{

}
void RpcClient::on_disconnected()
{

}