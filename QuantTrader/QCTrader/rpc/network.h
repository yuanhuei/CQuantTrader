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
        BaseMessage();
        ~BaseMessage();
        int Type;
        MSGPACK_DEFINE(Type);
    };
    class ClientMessage : public BaseMessage
    {
    public:

        MSGPACK_DEFINE(Type, Information, func_name, func_para_subReq, func_para_orderReq, func_para_cancelReq);

        //��Ϣ
        std::string Information;
        std::string    func_name;
        SubscribeReq   func_para_subReq;
        OrderReq       func_para_orderReq;
        CancelOrderReq func_para_cancelReq;


        //Ĭ�Ϲ��캯��
        ClientMessage();
        ~ClientMessage();

    };
    class ServerMessage : public BaseMessage
    {
    public:

        MSGPACK_DEFINE(Type, Information, str_EventType, event_timer, event_tick, event_trade, event_stoporder, event_contract,
            event_position, event_account, event_error, event_log, strReturnType, iReturn,strReturn);

        //��Ϣ
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
        //Ĭ�Ϲ��캯��
        ServerMessage();
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
                std::cout << "Msgpackѹ������ʧ�ܡ�" << std::endl;
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
        //ѹ��/�������
        msgpack::sbuffer m_sbuf;

        BaseMessage* GetMessage(const msgpack::object& obj);

        //ѹ��/���������
    };

    class Network
    {
    public:
        Network();
        ~Network();

        bool Init(int zmqType, const std::string& address);

        bool SetSocket(int zmqType, const std::string& address);
    private:
        //ͨ��socket
        void* m_socket;
        //���绷��
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