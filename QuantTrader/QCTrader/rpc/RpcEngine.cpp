#include "RpcEngine.h"
#include"rfc_frame.h"
#include"../gateway/gatewaymanager.h"
#include"../MainWindow.h"
#include"../event_engine/eventengine.h"
#include<string>
#include"network.h"
using namespace NetworkTool;

RpcEngine::RpcEngine(MainWindow *mainwindow)
{
	m_RpcServer = new RpcServer(this);
    m_mainwindow = mainwindow;
	m_gatewaymanager = mainwindow->m_gatewaymanager;
    m_eventengine = mainwindow->m_eventengine;

	rep_address = "tcp://*:2014";
	pub_address = "tcp://*:4102";
	init_server();
	load_setting();
	register_event();
}
RpcEngine::~RpcEngine()
{
	delete m_RpcServer;
}
void RpcEngine::register_event()
{
   // m_eventengine->RegEvent("",this.process_event);//self.event_engine.register_general(self.process_event)
    m_eventengine->RegEvent(EVENT_TICK, std::bind(&RpcEngine::process_event, this, std::placeholders::_1));
    m_eventengine->RegEvent(EVENT_ORDER, std::bind(&RpcEngine::process_event, this, std::placeholders::_1));
    m_eventengine->RegEvent(EVENT_STOP_ORDER, std::bind(&RpcEngine::process_event, this, std::placeholders::_1));

    m_eventengine->RegEvent(EVENT_TRADE, std::bind(&RpcEngine::process_event, this, std::placeholders::_1));
    m_eventengine->RegEvent(EVENT_POSITION, std::bind(&RpcEngine::process_event, this, std::placeholders::_1));
    m_eventengine->RegEvent(EVENT_TIMER, std::bind(&RpcEngine::process_event, this, std::placeholders::_1));
    //m_eventengine->RegEvent(EVENT_LOG, std::bind(&RpcEngine::v, this, std::placeholders::_1));

}
void RpcEngine::call_func(std::vector<ClientMessage>& vMessage, ServerMessage& returnMessage)
{
    if (vMessage[0].func_name == "subscribe")
    {
        m_gatewaymanager->subscribe(vMessage[1].func_para_subReq, "CTP");
        returnMessage.strReturnType = "void";
    }
    else if (vMessage[0].func_name == "sendOrder")
    {
        returnMessage.strReturn=m_gatewaymanager->sendOrder(vMessage[1].func_para_orderReq, "CTP");
        returnMessage.strReturnType = "string";
    }
    else if (vMessage[0].func_name == "cancelOrder")
    {
        m_gatewaymanager->cancelOrder(vMessage[1].func_para_cancelReq, "CTP");
        returnMessage.strReturnType = "void";
    }
}

void RpcEngine::init_server()
{
	//m_RpcServer->fun_register(m_gatewaymanager-);
}
void RpcEngine::load_setting()
{

}
void RpcEngine::save_setting()
{

}
bool RpcEngine::start(std::string  str_rep_address, std::string str_pub_address)
{
    if (m_RpcServer->isActive())
    {
        write_log("RPC服务运行中");
        return true;
    }
    rep_address = str_rep_address;
    pub_address = str_pub_address;

    try
    {
        m_RpcServer->start(rep_address, pub_address);

        save_setting();
        write_log("RPC服务启动成功");
    }
    catch (...)
    {
        //std::string  msg = traceback.format_exc();
        write_log("RPC服务启动失败");
        return false;

    }
    return true;
}
void RpcEngine::stop()
{
    if (m_RpcServer->isActive()==false)
    {
        write_log("RPC服务未启动");
        return;
    }
    m_RpcServer->stop();
    m_RpcServer->join();
    return;

}
void RpcEngine::close()
{
    stop();

}
void RpcEngine::process_event(std::shared_ptr<Event>e)
{
    ServerMessage cmessage;
    if (e->GetEventType() == EVENT_TICK)
    {
        std::shared_ptr<Event_Tick>pEvent = std::static_pointer_cast<Event_Tick>(e);
        cmessage.event_tick = *pEvent;
        cmessage.str_EventType = EVENT_TICK;
    }
    else if(e->GetEventType() == EVENT_TRADE)
    {
        std::shared_ptr<Event_Trade>pEvent = std::static_pointer_cast<Event_Trade>(e);
        cmessage.event_trade = *pEvent;
        cmessage.str_EventType = EVENT_TRADE;
    }
    else if (e->GetEventType() == EVENT_ORDER)
    {
        std::shared_ptr<Event_Order>pEvent = std::static_pointer_cast<Event_Order>(e);
        cmessage.event_order = *pEvent;
        cmessage.str_EventType = EVENT_ORDER;
    }
    else if (e->GetEventType() == EVENT_LOG)
    {
        std::shared_ptr<Event_Log>pEvent = std::static_pointer_cast<Event_Log>(e);
        cmessage.event_log = *pEvent;
        cmessage.str_EventType = EVENT_LOG;
    }


    if (m_RpcServer->isActive())
        m_RpcServer->publish("Event", cmessage);
}
void RpcEngine::write_log(std::string strLog)
{
    m_mainwindow->write_log(strLog, "RP_SERVER");
}