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

        MSGPACK_DEFINE(Type, Information);

        //��Ϣ
        std::vector<std::string> Information;

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