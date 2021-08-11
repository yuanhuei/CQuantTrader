#include "rfc_frame.h"
#include <msgpack.hpp>
#include<qdatetime.h>
#include<iostream>
#include<windows.h>
#include<stdio.h>

#define KEEP_ALIVE_TOPIC "_keep_alive"
#define KEEP_ALIVE_INTERVAL 1 //1Ãë
#define KEEP_ALIVE_TOLERANCE 30 //30Ãë

void generate_certificates(std::string strname)
{

}

RpcServer::RpcServer(RpcTestDialog* pRpctestDialog)
{
	m_socket_rep = new zmq::socket_t(m_zmqcontext, zmq::socket_type::rep);
	m_socket_pub = new zmq::socket_t(m_zmqcontext, zmq::socket_type::pub);
	m_rpctestDialog = pRpctestDialog;

	//msgpack::type::tuple

}

RpcServer::~RpcServer()
{
	delete m_socket_pub;
	delete m_socket_rep;

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
		if (rc == 0)
			continue;
		zmq::message_t msg;
		m_socket_rep->recv(&msg);
		std::string strRec = (char*)msg.data();
		std::cout << "Received " <<strRec<< std::endl;
		outputString(strRec);
		//sleep(1);

		zmq::message_t reply;
		std::string strReply = "Received:" + strRec;
		snprintf((char*)reply.data(), strReply.size(), "%s", (char*)strReply.c_str());
		memcpy(reply.data(), "World", 5);
		m_socket_rep->send(reply);
	}
}
void RpcServer::publish(std::string strTopic, std::string strData)
{
	m_threadMutex.lock();
	const char* p = strTopic.c_str();
	zmq::message_t msg;
	snprintf((char*)msg.data(), strTopic.size(), "%s", p);
	m_socket_pub->send(msg, zmq::send_flags::dontwait);
	m_threadMutex.unlock();

}
void RpcServer::fun_register()
{

}
void RpcServer::outputString(std::string strText)
{
	m_rpctestDialog->write_log(strText, "rpcserver");
}


RpcClient::RpcClient(RpcTestDialog* pRpctestDialog)
{
	m_socket_req = new zmq::socket_t(m_zmqcontext, zmq::socket_type::req);
	m_socket_sub = new zmq::socket_t(m_zmqcontext, zmq::socket_type::sub);
	m_rpctestDialog = pRpctestDialog;


}

RpcClient::~RpcClient()
{
	delete m_socket_req;
	delete m_socket_sub;

}

void RpcClient::start(std::string req_address,std::string sub_address)
{
	if (m_active)
		return;

	m_socket_req->connect(req_address);
	m_socket_sub->connect(sub_address);
	m_active = true;
	m_thread = std::thread::thread(std::bind(&RpcClient::run, this));
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
	int pull_tolerance = KEEP_ALIVE_TOLERANCE * 1000;
	subscribe_topic("'");
	while (m_active)
	{
		zmq_pollitem_t items[1];
		/* First item refers to socket 'socket' */
		items[0].socket = m_socket_sub;
		items[0].events = ZMQ_POLLIN;
		//Use poll to wait event arrival, waiting time is 1 second(1000 milliseconds)
		int rc = zmq_poll(items, 1, pull_tolerance);
		if (rc == 0)
		{
			on_disconnected();
			continue;
		}
		zmq::message_t msg;
		//zmq::send_multipart()
		m_socket_sub->recv(&msg);
		std::string strRec = (char*)msg.data();
		std::cout << "Received " <<strRec<< std::endl;
		outputString("sub port received:" + strRec);
	}
	m_socket_req->close();
	m_socket_sub->close();

}
void RpcClient::callback()
{

}
void RpcClient::subscribe_topic(std::string strTopic)
{
	const char* filter = strTopic.c_str();
	m_socket_sub->setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));
}
void RpcClient::on_disconnected()
{
	std::cout<<"RpcServer has no response over {tolerance} seconds, please check you connection.";
}
std::string RpcClient::sendRequest(std::string strReq)
{

	zmq::message_t requestMsg;
	snprintf((char*)requestMsg.data(), strReq.size(), "%s", (char*)strReq.c_str());
	//memcpy(request.data(), "World", 5);
	m_socket_req->send(requestMsg);

	zmq::message_t receiveMsg;
	m_socket_req->recv(&receiveMsg);
	std::string strRec = (char*)receiveMsg.data();
	std::cout << "Received " << strRec << std::endl;
	outputString("reply port received:" + strRec);
	return strRec;
}
void RpcClient::outputString(std::string strText)
{
	m_rpctestDialog->write_log(strText, "rpcclient");
}
