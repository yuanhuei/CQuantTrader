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

	ServerMessage returnMessage;
	std::tuple<SubscribeReq> inputPara(subscribeReq);
	MethodCallMessage<std::tuple<SubscribeReq>> callMethod("subscribe", inputPara);

	m_client->call_server(callMethod, returnMessage);
	
}
std::string RpcGateway::sendOrder(OrderReq& req)
{


	ServerMessage returnMessage;
	std::tuple<OrderReq> inputPara(req);
	MethodCallMessage<std::tuple<OrderReq>> callMethod("sendOrder", inputPara);

	m_client->call_server(callMethod, returnMessage);
	return returnMessage.strReturn;
}
void RpcGateway::cancelOrder(CancelOrderReq& req)
{

	ServerMessage returnMessage;
	std::tuple<CancelOrderReq> inputPara(req);
	MethodCallMessage<std::tuple<CancelOrderReq>> callMethod("cancelOrder", inputPara);
	m_client->call_server(callMethod, returnMessage);
}
void RpcGateway::query_all()
{

}
void RpcGateway::close()
{
	m_client->stop();
	m_client->join();
}
void RpcGateway::client_callback(std::string topic, ServerMessage emessage)
{
	ServerMessage cmessage;
	//Event event();
	std::shared_ptr<Event>e;// = std::make_shared<Event>(event);
	if (emessage.str_EventType == EVENT_TICK)
	{
		//event = cmessage.event_tick; .
		e = std::make_shared<Event>(cmessage.event_tick);
	}
	else if (emessage.str_EventType == EVENT_TRADE)
	{
		e = std::make_shared<Event>(cmessage.event_trade);

	}
	else if (emessage.str_EventType == EVENT_ORDER)
	{
		e = std::make_shared<Event>(cmessage.event_order);

	}
	else if (emessage.str_EventType == EVENT_LOG)
	{
		e = std::make_shared<Event>(cmessage.event_log);
	}


	
	//e->gatewayname = "CTP";
	m_eventengine->Put(e);
}
void RpcGateway::qryAccount()//查询账户资金
{
}
	
void RpcGateway::qryPosition()//查询持仓
{
}
std::string RpcGateway::GetExchangeName(std::string strSymbol)
{
	return "";
}
int  RpcGateway::GetSymbolSize(std::string strSymbol)
{
	return 0;
}
void RpcGateway::connect()//连接
{}


