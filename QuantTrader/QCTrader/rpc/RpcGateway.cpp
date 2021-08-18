#include "RpcGateway.h"
#include "rfc_frame.h"
#include"network.h"
using namespace NetworkTool;
RpcGateway::RpcGateway(EventEngine* eventengine, std::string gatewayname):QCGateway(eventengine, gatewayname)
{
	m_client = new RpcClient(this);

}
RpcGateway::~RpcGateway()
{
	delete m_client;

}
void RpcGateway::connect(std::string req_address,std::string pub_address)
{
	//req_address = setting["主动请求地址"]
	//pub_address = setting["推送订阅地址"]

	m_client->subscribe_topic("");
	m_client->start(req_address, pub_address);

	write_log("服务器连接成功，开始初始化查询");
	query_all();

}

void RpcGateway::subscribe(SubscribeReq& subscribeReq)
{
	std::vector <ClientMessage> vMessage;
	ClientMessage func_name, func_para_subReq;
	func_name.func_name = "subscribe";
	vMessage.push_back(func_name);

	func_para_subReq.func_para_subReq = subscribeReq;
	vMessage.push_back(func_para_subReq);

	m_client->call_server(vMessage);

}
std::string RpcGateway::sendOrder(OrderReq& req)
{
	std::vector <ClientMessage> vMessage;
	ClientMessage func_name, func_para_subReq;
	func_name.func_name = "sendOrder";
	vMessage.push_back(func_name);

	func_para_subReq.func_para_orderReq = req;
	vMessage.push_back(func_para_subReq);

	m_client->call_server(vMessage);
	return "";
}
void RpcGateway::cancelOrder(CancelOrderReq& req)
{
	std::vector <ClientMessage> vMessage;
	ClientMessage func_name, func_para_subReq;
	func_name.func_name = "cancelOrder";
	vMessage.push_back(func_name);

	func_para_subReq.func_para_cancelReq = req;
	vMessage.push_back(func_para_subReq);

	m_client->call_server(vMessage);
}
void RpcGateway::query_all()
{

}
void RpcGateway::close()
{
	m_client->stop();
	m_client->join();
}
void RpcGateway::client_callback(std::string topic, Event event)
{
	std::shared_ptr<Event>e = std::make_shared<Event>(event);
	//e->gatewayname = "CTP";
	//eventEngine->Put(e);
	m_eventengine->Put(e);
}