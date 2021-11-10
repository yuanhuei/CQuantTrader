#pragma once
#ifndef NETWORK_HP
#define NETWORK_HPP

#include<zmq.h>
#include<zmq.hpp>
#include<msgpack.hpp>

#include"qcstructs.h"
namespace NetworkTool
{
    class  BaseMessage
    {
    public:
        virtual void BaseMessage::output() {};


        //默认构造函数
        BaseMessage::BaseMessage()
        {
            Type = 0;
            strFunName = "NULL";
        };
        BaseMessage:: ~BaseMessage()
        {};
        int Type;
        std::string strFunName;
        MSGPACK_DEFINE(Type, strFunName);
    };
    //基于模板的客户端RPC调用 包含函数名称和输入参数的类
    template<class T>
    class MethodCallMessage : public BaseMessage
    {
    public:
        std::string Information;
        std::string    func_name;
        //std::tuple<...Args> fucnPara;
        T funcPara;
        //void remoteMethod(std::string funname, T t);
        MSGPACK_DEFINE(Type, strFunName,Information, func_name, funcPara);

        //默认构造函数
        MethodCallMessage(std::string strFun, T tFuncPara)
        {
            Type = 1000;
            strFunName = strFun;
            func_name = strFun;
            funcPara = tFuncPara;
        };
        MethodCallMessage()
        {
            Type = 1000;
        };
        ~MethodCallMessage() 
        {};
        void output() 
        {};

    };
    //客户端消息
    class ClientMessage : public BaseMessage
    {
    public:

        MSGPACK_DEFINE(Type, strFunName, Information, func_name);

        //信息
        std::string Information;
        std::string    func_name;

        //默认构造函数
        ClientMessage::ClientMessage() { Type = 1024;};
        ClientMessage::~ClientMessage() {};

    };

    //服务器端的消息封装
    class ServerMessage : public BaseMessage
    {
    public:

        MSGPACK_DEFINE(Type, strFunName, Information, str_EventType, event_timer, event_tick, event_trade, event_stoporder, event_contract,
            event_position, event_account, event_error, event_log, strReturnType, iReturn,strReturn);

        //信息
        bool bReturnResult = false;//request是否接受到server的正常reply
        std::vector<std::string> Information;
        std::string str_EventType;
        std::string strReturnType;
        int iReturn;
        std::string strReturn;

        Event_Timer event_timer;
        Event_Tick event_tick;
        Event_Trade  event_trade;
        Event_Order  event_order;
        Event_StopOrder  event_stoporder;
        Event_Contract  event_contract;
        Event_Position   event_position;
        Event_Account event_account;
        Event_Error   event_error;
        Event_Log event_log;
        //默认构造函数
        ServerMessage::ServerMessage() {
            Type = 2048;
            strReturn = "NULL";
        };
        ServerMessage::~ServerMessage() {};
    };
    class Msgpack
    {
    public:
        Msgpack(void);
        ~Msgpack(void);


        template<typename T>
        bool Pack(const T& t)
        {
            try
            {
                Release();
                msgpack::pack(m_sbuf, t);
                return true;
            }
            catch (...)
            {
                std::cout << "Msgpack压包数据失败。" << std::endl;
                return false;
            }
        };

        BaseMessage* Unpack(zmq_msg_t& msg);
        std::vector <ClientMessage>* Unpackvector(zmq_msg_t& msg);

        msgpack::sbuffer& GetSbuf();
        void Release();
        template<typename T>
        T* Convert(const msgpack::object& obj);

    private:
        //压包/解包工具
        msgpack::sbuffer m_sbuf;

        BaseMessage* GetMessage(const msgpack::object& obj);

        //压包/解包工具类
    };

    class Network
    {
    public:
        Network();
        ~Network();

        bool Init(int zmqType, const std::string& address);

        bool SetSocket(int zmqType, const std::string& address);
    private:
        //通信socket
        void* m_socket;
        //网络环境
        void* Context;

    };
    bool SendMsg(Msgpack* msgpack, zmq::socket_t* socket_t, zmq::send_flags flags = zmq::send_flags::none, bool isRelease = true);
    zmq_msg_t* ReceiveMessage(zmq::socket_t* socket_t, zmq::send_flags flags = zmq::send_flags::none);
    void CloseMsg(zmq_msg_t* msg);
    void Release(void* function, void* hint);
    template<typename T>
    T* Convert(const msgpack::object& obj);

};
#endif