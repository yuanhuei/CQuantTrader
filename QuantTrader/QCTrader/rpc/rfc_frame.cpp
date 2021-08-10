#include "rfc_frame.h"
#include <msgpack.hpp>
#include<qdatetime.h>
#include<iostream>
#include<windows.h>

#define KEEP_ALIVE_TOPIC "_keep_alive"
#define KEEP_ALIVE_INTERVAL 1 //1Ãë
#define KEEP_ALIVE_TOLERANCE 30 //30Ãë

void generate_certificates(std::string strname)
{

}

RpcServer::RpcServer()
{
	m_socket_rep = new zmq::socket_t(m_zmqcontext, zmq::socket_type::rep);
	m_socket_pub = new zmq::socket_t(m_zmqcontext, zmq::socket_type::pub);
	//msgpack::type::tuple

}

RpcServer::~RpcServer()
{


}

bool RpcServer::isActive()
{
	return m_active;
}

void RpcServer::start(std::string rep_address, std::string pub_address)
{
	if (m_active)
		return;

	m_socket_rep->bind(rep_address);
	m_socket_pub->bind(pub_address);
	m_active = true;
	m_thread = std::thread::thread(std::bind(&RpcServer::run, this));
	//zmq:;zmq_poll

}
void RpcServer::stop()
{
	m_active = false;

}
void RpcServer::join()
{
	m_thread.join();
}
void RpcServer::run()
{
	QDateTime start_time = QDateTime::currentDateTime();
	while (m_active)
	{
		QDateTime cur_time = QDateTime::currentDateTime();
		int delta = cur_time.secsTo(start_time);

		if (delta > KEEP_ALIVE_INTERVAL)
			publish(KEEP_ALIVE_TOPIC, cur_time.toString().toStdString());
		zmq_pollitem_t items[1];
		/* First item refers to socket 'socket' */
		items[0].socket = m_socket_rep;
		items[0].events = ZMQ_POLLIN;
		//Use poll to wait event arrival, waiting time is 1 second(1000 milliseconds)
		int rc = zmq_poll(items, 1, 1000);
		if (rc = 0)
			continue;
		zmq::message_t msg;
		m_socket_rep->recv(&msg);
		std::cout << "Received Hello" << std::endl;

		//sleep(1);

		zmq::message_t reply(5);
		memcpy(reply.data(), "World", 5);
		m_socket_rep->send(reply);
	}
}
void RpcServer::publish(std::string strTopic, std::string strData)
{
	m_threadMutex.lock();
	m_socket_pub->send((void*)&(strTopic.c_str()), zmq::send_flags::dontwait);
	m_threadMutex.unlock();

}
void RpcServer::fun_register()
{

}

RpcClient::RpcClient()
{
	m_socket_req = new zmq::socket_t(m_zmqcontext, zmq::socket_type::req);
	m_socket_sub = new zmq::socket_t(m_zmqcontext, zmq::socket_type::sub);


}

RpcClient::~RpcClient()
{

}

void RpcClient::start(std::string req_address,std::string sub_address)
{
	if (m_active)
		return;

	m_socket_req->connect(req_address);
	m_socket_sub->connect(sub_address);
	m_active = true;
	m_thread = std::thread::thread(std::bind(&RpcServer::run, this));
}
void RpcClient::stop()
{
	m_active = false;

}
void RpcClient::join()
{
	m_thread.join();
}
void RpcClient::run()
{

}
void RpcClient::callback()
{

}
void RpcClient::subscribe_topic(std::string strTopic)
{
	//m_socket_sub->setsockopt()
}
void RpcClient::on_disconnected()
{
	std::cout<<"RpcServer has no response over {tolerance} seconds, please check you connection.";
}