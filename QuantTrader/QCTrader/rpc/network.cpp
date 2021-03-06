

#include"network.h"
#include<string>
#include<cassert>
#include<iostream>



namespace NetworkTool
{

        //MSGPACK_DEFINE(Type);

        //消息类型
       // int Type;

        //默认构造函数
    BaseMessage::BaseMessage()
    {
        Type = 0;
    }
    BaseMessage:: ~BaseMessage()
    {}



        //MSGPACK_DEFINE(Type, Information,func_name, func_para_subReq, func_para_orderReq, func_para_cancelReq);

        //信息
        //std::string Information;
       // std::string    func_name;
     //   SubscribeReq   func_para_subReq;
       // OrderReq       func_para_orderReq;
      //  CancelOrderReq func_para_cancelReq;


        //默认构造函数
    ClientMessage::ClientMessage()
    {
        Type = 1024;
    }
    ClientMessage::  ~ClientMessage()
    {}

    //来自服务端的消息


      //  MSGPACK_DEFINE(Type, Information);

        //信息
       // std::vector<std::string> Information;

        //默认构造函数
    ServerMessage::ServerMessage()
    {
        Type = 2048;
        //m_event = Event("event");
    }


        // 功能 ：构造函数。
        // 参数 ：无。
        // 返回 ：无。
    Msgpack::Msgpack(void) { }

        // 功能 ：析构函数。
        // 参数 ：无。
        // 返回 ：无。
    Msgpack::  ~Msgpack(void) { }

        // 功能 ：压包数据。
        // 参数 ：要压包的数据。
        // 返回 ：true表示压包成功。


        // 功能 ：解包数据。
        // 参数 ：zmq消息体。
        // 返回 ：返回指向基类消息的指针。
    std::vector <ClientMessage>* Msgpack::Unpackvector(zmq_msg_t& msg)
    {
        try
        {
            int size = zmq_msg_size(&msg);
            if (size > 0)
            {
                Release();
                m_sbuf.write((char*)zmq_msg_data(&msg), size);

                std::vector <ClientMessage>* vMessage=new std::vector <ClientMessage>;
                msgpack::object_handle  objhand = msgpack::unpack(m_sbuf.data(), m_sbuf.size());
                msgpack::object objmsg = objhand.get();
                objmsg.convert(*vMessage);
                return vMessage;
                //return GetMessage(obj);
            }
        }
        catch (...)
        {
            //吃掉异常
        }
        return NULL;

    }

    BaseMessage* Msgpack::Unpack(zmq_msg_t& msg)
    {
        try
        {
            int size = zmq_msg_size(&msg);
            if (size > 0)
            {
                Release();
                m_sbuf.write((char*)zmq_msg_data(&msg), size);
                // size_t offset = 0;
                // msgpack::zone z;
                // msgpack::object obj;

                    //msgpack::object_handle oh = msgpack::unpack(m_sbuf.data(), m_sbuf.size());   // 反序列化成实例
                    //msgpack::object deserialized = oh.get();
                    //msgpack::unpack(m_sbuf.data(), m_sbuf.size(), &offset, &z, &obj);


                msgpack::object_handle  objhand = msgpack::unpack(m_sbuf.data(), m_sbuf.size());
                msgpack::object objmsg = objhand.get();
                BaseMessage bmessage;
                objmsg.convert(bmessage);
                switch (bmessage.Type)
                {
                case 1024:
                    return Convert<ClientMessage>(objmsg);
                case 2048:
                    return Convert<ServerMessage>(objmsg);
                default:
                    return NULL;
                }
                //return GetMessage(obj);
            }
        }
        catch (...)
        {
            //吃掉异常
        }
        return NULL;
    }

        // 功能 ：获取压包/解包工具。
        // 参数 ：无。
        // 返回 ：压包/解包工具。
    msgpack::sbuffer& Msgpack::GetSbuf()
    {
        return m_sbuf;
    }



    // 功能 ：释放上一次的数据资源。
    // 参数 ：无。
    // 返回 ：无。
    void Msgpack::Release()
    {
        m_sbuf.clear();
        m_sbuf.release();
    }

    // 功能 ：获取消息。
    // 参数 ：用于转换的msgpack::object。
    // 返回 ：指向消息基类的指针。
    BaseMessage* Msgpack::GetMessage(const msgpack::object& obj)
    {
        BaseMessage bmessage;
        obj.convert(bmessage);
        switch (bmessage.Type)
        {
        case 1024:
            return Convert<ClientMessage>(obj);
        case 2048:
            return Convert<ServerMessage>(obj);
        default:
            return NULL;
        }
    }

    // 功能 ：将压包后的数据转换为具体的类。
    // 参数 ：用于转换的msgpack::object。
    // 返回 ：指向T的指针。
    template<typename T>
    T* Msgpack::Convert(const msgpack::object& obj)
    {
        T* t = new T();
        obj.convert(*t);
        return t;
    }



    // 功能 ：构造函数。
    // 参数 ：无。
    // 返回 ：无。
    Network::Network() : m_socket(NULL)
    {
        Context = zmq_ctx_new();
    }

    // 功能 ：析构函数。
    // 参数 ：无。
    // 返回 ：无。
    Network::~Network()
    {
        if (m_socket != NULL)
        {
            zmq_close(m_socket);
            m_socket = NULL;
        }
        if (Context != NULL)
            delete Context;
    }

    // 功能 ：初始化socket。
    // 参数 ：zmqType表示ZMQ的模式，address表示socket绑定或连接地址。
    // 返回 ：true表示初始化成功，false表示失败。
    bool Network::Init(int zmqType, const std::string& address)
    {
        try
        {
            m_socket = zmq_socket(Context, zmqType);
            return SetSocket(zmqType, address);
        }
        catch (...)
        {
            std::cout << "Network初始化失败。" << std::endl;
            return false;
        }
    }

    // 功能 ：设置socket。
    // 参数 ：zmqType表示ZMQ的模式，address表示socket绑定或连接地址。
    // 返回 ：true表示设置成功，false表示设置失败。
    bool Network::SetSocket(int zmqType, const std::string& address)
    {
        int result = -1;
        switch (zmqType)
        {
        case ZMQ_REP:
        case ZMQ_PUB:
            result = zmq_bind(m_socket, address.c_str());
            break;
        case ZMQ_REQ:
            result = zmq_connect(m_socket, address.c_str());
            break;
        case ZMQ_SUB:
            result = zmq_connect(m_socket, address.c_str());
            assert(result == 0);
            result = zmq_setsockopt(m_socket, ZMQ_SUBSCRIBE, "", 0);
            break;
        default:
            return false;
        }
        assert(result == 0);
        return true;
    }

// 功能 ：发送完消息后，释放消息资源。
// 参数 ：function为函数地址，hint指向要释放资源的对象。
// 返回 ：无。
    void Release(void* function, void* hint)
    {
        Msgpack* msgpack = (Msgpack*)hint;
        if (msgpack != NULL)
        {
            delete msgpack;
            msgpack = NULL;
        }
    }

//整个程序共用一个context
//void* Context= zmq_ctx_new();
        // 功能 ：发送消息。
    // 参数 ：指向Msgpack的指针，isRelease如果为true表示发送消息后即刻释放资源。
    // 返回 ：true表示发送成功，false表示发送失败。
    bool SendMsg(Msgpack* msgpack, zmq::socket_t* socket_t, zmq::send_flags flags, bool isRelease )
    {
        try
        {
            zmq_msg_t msg;
            //zmq_msg_init(&msg);
            int i, j;
            size_t messageSize = msgpack->GetSbuf().size();
            if (isRelease)
            {
                i = zmq_msg_init_data(&msg, msgpack->GetSbuf().data(), messageSize, Release, msgpack);
            }
            else
            {
                i = zmq_msg_init_data(&msg, msgpack->GetSbuf().data(), messageSize, 0, 0);
            }
            //j=zmq_msg_send(&msg, socket_t, int(flags));
            size_t tsize = zmq_msg_size(&msg);
            //i=zmq_msg_send(&msg, socket_t, 0);

            zmq::message_t msg_t(messageSize);
            memcpy(msg_t.data(), msgpack->GetSbuf().data(), messageSize);
            //i = zmq_msg_copy(msg_t.handle(),&msg);
            //memcpy(msg_t.data(), &msg, zmq_msg_size(&msg));
            //size_t bSize=socket_t->send(&msg,tsize,(int) flags);
            bool b = socket_t->send(msg_t, (int)flags);
            return true;
        }
        catch (...)
        {
            std::cout << "Network发送失败。" << std::endl;
            return false;
        }
    }

// 功能 ：接收消息。
// 参数 ：无。
// 返回 ：指向消息的指针。
    zmq_msg_t* ReceiveMessage(zmq::socket_t* socket_t, zmq::send_flags flags)
    {
        zmq_msg_t* reply = NULL;
        try
        {
            reply = new zmq_msg_t();
            zmq_msg_init(reply);
            //size_t size=zmq_msg_recv(reply, socket_t, int(flags));
            zmq::message_t reply_message;
            bool brecov = socket_t->recv(&reply_message, int(flags));
            if (brecov == false)
                return NULL;
            int i = zmq_msg_copy(reply, reply_message.handle());
            // *reply = *reply_message.handle();
            return reply;
        }
        catch (...)
        {
            if (reply != NULL)
            {
                delete reply;
            }
            return NULL;
        }
    }

    // 功能 ：关闭消息。
    // 参数 ：指向消息的指针。
    // 返回 ：无。
    void CloseMsg(zmq_msg_t* msg)
    {
        try
        {
            zmq_msg_close(msg);
            msg = NULL;
        }
        catch (...)
        {
            msg = NULL;
        }
    }
    // 功能 ：将压包后的数据转换为具体的类。
// 参数 ：用于转换的msgpack::object。
// 返回 ：指向T的指针。
    template<typename T>
    T* Convert(const msgpack::object& obj)
    {
        T* t = new T();
        obj.convert(*t);
        return t;
    }
}

