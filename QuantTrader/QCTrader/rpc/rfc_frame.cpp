#include "rfc_frame.h"
#include <msgpack.hpp>
#include<qdatetime.h>
#include<iostream>
#include<windows.h>
#include<stdio.h>
#include "network.hpp"

using namespace Message;
using namespace MsgTool;

#define KEEP_ALIVE_TOPIC "_keep_alive"
#define KEEP_ALIVE_INTERVAL 1 //1秒
#define KEEP_ALIVE_TOLERANCE 30 //30秒

void generate_certificates(std::string strname)
{

}

RpcServer::RpcServer(RpcTestDialog* pRpctestDialog)
{
	m_socket_rep = new zmq::socket_t(m_zmqcontext, zmq::socket_type::rep);
	m_socket_pub = new zmq::socket_t(m_zmqcontext, zmq::socket_type::pub);
	m_rpctestDialog = pRpctestDialog;


	int nNetTimeout = 5000;//1秒，
	//设置发送超时
	m_socket_rep->setsockopt(ZMQ_SNDTIMEO, (char*)&nNetTimeout, sizeof(int));
	m_socket_rep->setsockopt(ZMQ_RCVTIMEO, (char*)&nNetTimeout, sizeof(int));
	//设置接收超时
	m_socket_pub->setsockopt(ZMQ_SNDTIMEO, (char*)&nNetTimeout, sizeof(int));
	m_socket_pub->setsockopt(ZMQ_RCVTIMEO, (char*)&nNetTimeout, sizeof(int));
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
	outputString("RpcServer running\n");
	while (m_active)
	{
		
		QDateTime cur_time = QDateTime::currentDateTime();
		int delta = -cur_time.secsTo(start_time);

		if (delta > KEEP_ALIVE_INTERVAL)
			publish(KEEP_ALIVE_TOPIC, cur_time.toString().toStdString());
		start_time = QDateTime::currentDateTime();
		//zmq_pollitem_t items[2];
		/* First item refers to socket 'socket' */
		//zmq_fd_t fd=0;
		//items[0].socket = m_socket_rep;
		//items[0].events = ZMQ_POLLIN;
		//items[1].socket = NULL;
		//items[1].fd = fd;
		//items[1].events = ZMQ_POLLIN;
		//Use poll to wait event arrival, waiting time is 1 second(1000 milliseconds)
		//int rc = zmq_poll(items, 2, 10000);
		//if (rc <1)
			//continue;
		zmq::message_t msg;
		bool bRec=m_socket_rep->recv(&msg);
		if (bRec)
		{
			std::string strRec = (char*)msg.data();
			std::cout << "Received " << strRec << std::endl;
			outputString("Received:" + strRec + "\n");

			std::string strReply = "Received:" + strRec;
			zmq::message_t reply(strReply.size()+1);
			snprintf((char*)reply.data(), strReply.size()+1, "%s", (char*)strReply.c_str());
			//memcpy(reply.data(), "World", 5);
			m_socket_rep->send(reply, zmq::send_flags::dontwait);
			continue;
		}
		//Sleep(1000);
	}
	outputString("RpcServer thread exit\n");
	char cLastEndPoint[30];
	size_t tLen = 30;
	m_socket_rep->getsockopt(ZMQ_LAST_ENDPOINT, cLastEndPoint, &tLen);
	m_socket_rep->unbind(cLastEndPoint);
	m_socket_pub->getsockopt(ZMQ_LAST_ENDPOINT, cLastEndPoint, &tLen);
	m_socket_pub->unbind(cLastEndPoint);

}
void RpcServer::publish(std::string strTopic, std::string strData)
{
	m_threadMutex.lock();
	/*
	const char* p = strTopic.c_str();
	zmq::message_t msg(strTopic.size()+1);
	snprintf((char*)msg.data(), strTopic.size()+1, "%s", p);
	m_socket_pub->send(msg, zmq::send_flags::dontwait);
	*/
	ServerMessage cmessage;
	cmessage.Information.push_back(strTopic);// "I come form Client.";
	Msgpack msgpack;
	bool result = msgpack.Pack<ServerMessage>(cmessage);
	if (result)
		result = MsgTool::SendMessage(&msgpack, m_socket_pub, zmq::send_flags::dontwait,false);
		
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

	int nNetTimeout = 5000;//1秒，
	//设置发送超时
	m_socket_req->setsockopt(ZMQ_SNDTIMEO,(char*) & nNetTimeout, sizeof(int));
	m_socket_req->setsockopt(ZMQ_RCVTIMEO, (char*)&nNetTimeout, sizeof(int));

	//设置接收超时
	m_socket_sub->setsockopt(ZMQ_SNDTIMEO,(char*) & nNetTimeout, sizeof(int));
	m_socket_sub->setsockopt(ZMQ_RCVTIMEO, (char*)&nNetTimeout, sizeof(int));


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
	subscribe_topic("");
	outputString("RpcClient running\n");
	while (m_active)
	{
		
		//zmq_pollitem_t items[1];
		/* First item refers to socket 'socket' */
		//items[0].socket = m_socket_sub;
		//items[0].events = ZMQ_POLLIN;
		//Use poll to wait event arrival, waiting time is 1 second(1000 milliseconds)
		//int rc = zmq_poll(items, 1, pull_tolerance);
		//if (rc < 1)
		//{
		//	on_disconnected();
		//	continue;
		//
		/*
		zmq::message_t msg;
		bool bRec = m_socket_sub->recv(&msg);
		if (bRec)
		{
			std::string strRec = (char*)msg.data();
			std::cout << "Received " << strRec << std::endl;
			if (strRec != KEEP_ALIVE_TOPIC)
				outputString("sub port received:" + strRec + "\n");
		}
		*/
		zmq_msg_t* msg = ReceiveMessage(m_socket_sub);
		if (msg!=NULL)
		{
			//zmq_msg_t* msg_t = msg.handle();
			
			Msgpack msgpack;

			BaseMessage* bmessage = msgpack.Unpack(*msg);
			CloseMsg(msg);
			if (bmessage != NULL && bmessage->Type == 2048)
			{
				ServerMessage* smessage = static_cast<ServerMessage*>(bmessage);
				if (smessage != NULL && smessage->Information.size() > 0)
				{
					std::cout << smessage->Information[0] << std::endl;
					if (smessage->Information[0] != KEEP_ALIVE_TOPIC)
						outputString("sub port received:" + smessage->Information[0] + "\n");
				}
				delete smessage;
				smessage = NULL;
				bmessage = NULL;
			}
		}
		/*
		zmq::message_t msg;
		bool bRec=m_socket_sub->recv(&msg);
		if (bRec)
		{
			std::string strRec = (char*)msg.data();
			std::cout << "Received " << strRec << std::endl;
			if(strRec!= KEEP_ALIVE_TOPIC)
				outputString("sub port received:" + strRec+"\n");
		}
		*/
		//zmq_poll()
		//Sleep(1000);
	}
	outputString("RpcClient thread exit\n");
	//m_socket_req->close();
	//m_socket_sub->close();
	zmq_close(m_socket_req);
	zmq_close(m_socket_sub);

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

	zmq::message_t requestMsg(strReq.size()+1);
	snprintf((char*)requestMsg.data(), strReq.size()+1, "%s", (char*)strReq.c_str());
	//memcpy(request.data(), "World", 5);
	bool bSend=m_socket_req->send(requestMsg);

	if (bSend)
	{
		zmq::message_t receiveMsg;
		bool bReq=m_socket_req->recv(&receiveMsg);
		if (bReq)
		{
			std::string strRec = (char*)receiveMsg.data();
			std::cout << "Received " << strRec << std::endl;
			outputString("reply port received:" + strRec + "\n");
			return strRec;
		}
	}
	return "";
}
void RpcClient::outputString(std::string strText)
{
	m_rpctestDialog->write_log(strText, "rpcclient");
}
