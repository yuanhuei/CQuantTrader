#include "RpcEngine.h"
#include"rfc_frame.h"
#include"../gateway/gatewaymanager.h"
#include"../MainWindow.h"
#include"../event_engine/eventengine.h"
#include<string>

RpcEngine::RpcEngine(MainWindow *mainwindow)
{
	m_RpcServer = new RpcServer(NULL);
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
    if (m_RpcServer->isActive())
        m_RpcServer->publish("", "");
}
void RpcEngine::write_log(std::string strLog)
{
    m_mainwindow->write_log(strLog, "RP_SERVER");
}