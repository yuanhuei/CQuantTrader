

#include"network.h"
#include<string>
#include<cassert>
#include<iostream>



namespace NetworkTool
{

    /*
    //Ĭ�Ϲ��캯��
    ClientMessage::ClientMessage()
    {
        Type = 1024;
    }
    ClientMessage::  ~ClientMessage()
    {}

    //���Է���˵���Ϣ


      //Ĭ�Ϲ��캯��
    ServerMessage::ServerMessage()
    {
        Type = 2048;
        strReturn = "NULL";
        //m_event = Event("event");
    }
    ServerMessage::~ServerMessage()
    {}
    */


        // ���� �����캯����
        // ���� ���ޡ�
        // ���� ���ޡ�
    Msgpack::Msgpack(void) { }

        // ���� ������������
        // ���� ���ޡ�
        // ���� ���ޡ�
    Msgpack::  ~Msgpack(void) { }

        // ���� ��ѹ�����ݡ�
        // ���� ��Ҫѹ�������ݡ�
        // ���� ��true��ʾѹ���ɹ���


        // ���� ��������ݡ�
        // ���� ��zmq��Ϣ�塣
        // ���� ������ָ�������Ϣ��ָ�롣
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
            //�Ե��쳣
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

                    //msgpack::object_handle oh = msgpack::unpack(m_sbuf.data(), m_sbuf.size());   // �����л���ʵ��
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
                case 1000:
                {
                    if(bmessage.strFunName=="caculate_x_y")
                    { 
                        MethodCallMessage<std::tuple<int, int>>* t = new MethodCallMessage<std::tuple<int, int>>();
                        objmsg.convert(*t);
                        return t;
                    }
                    else if (bmessage.strFunName == "cancelOrder")
                    {
                        MethodCallMessage<std::tuple<CancelOrderReq>>* t = new MethodCallMessage<std::tuple<CancelOrderReq>>();
                        objmsg.convert(*t);
                        return t;
                    }

                    
                }
                    
                default:
                    return NULL;
                }
                //return GetMessage(obj);
            }
        }
        catch (...)
        {
            //�Ե��쳣
        }
        return NULL;
    }

        // ���� ����ȡѹ��/������ߡ�
        // ���� ���ޡ�
        // ���� ��ѹ��/������ߡ�
    msgpack::sbuffer& Msgpack::GetSbuf()
    {
        return m_sbuf;
    }



    // ���� ���ͷ���һ�ε�������Դ��
    // ���� ���ޡ�
    // ���� ���ޡ�
    void Msgpack::Release()
    {
        m_sbuf.clear();
        m_sbuf.release();
    }

    // ���� ����ȡ��Ϣ��
    // ���� ������ת����msgpack::object��
    // ���� ��ָ����Ϣ�����ָ�롣
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

    // ���� ����ѹ���������ת��Ϊ������ࡣ
    // ���� ������ת����msgpack::object��
    // ���� ��ָ��T��ָ�롣
    template<typename T>
    T* Msgpack::Convert(const msgpack::object& obj)
    {
        T* t = new T();
        obj.convert(*t);
        return t;
    }



    // ���� �����캯����
    // ���� ���ޡ�
    // ���� ���ޡ�
    Network::Network() : m_socket(NULL)
    {
        Context = zmq_ctx_new();
    }

    // ���� ������������
    // ���� ���ޡ�
    // ���� ���ޡ�
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

    // ���� ����ʼ��socket��
    // ���� ��zmqType��ʾZMQ��ģʽ��address��ʾsocket�󶨻����ӵ�ַ��
    // ���� ��true��ʾ��ʼ���ɹ���false��ʾʧ�ܡ�
    bool Network::Init(int zmqType, const std::string& address)
    {
        try
        {
            m_socket = zmq_socket(Context, zmqType);
            return SetSocket(zmqType, address);
        }
        catch (...)
        {
            std::cout << "Network��ʼ��ʧ�ܡ�" << std::endl;
            return false;
        }
    }

    // ���� ������socket��
    // ���� ��zmqType��ʾZMQ��ģʽ��address��ʾsocket�󶨻����ӵ�ַ��
    // ���� ��true��ʾ���óɹ���false��ʾ����ʧ�ܡ�
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

// ���� ����������Ϣ���ͷ���Ϣ��Դ��
// ���� ��functionΪ������ַ��hintָ��Ҫ�ͷ���Դ�Ķ���
// ���� ���ޡ�
    void Release(void* function, void* hint)
    {
        Msgpack* msgpack = (Msgpack*)hint;
        if (msgpack != NULL)
        {
            delete msgpack;
            msgpack = NULL;
        }
    }

//����������һ��context
//void* Context= zmq_ctx_new();
        // ���� ��������Ϣ��
    // ���� ��ָ��Msgpack��ָ�룬isRelease���Ϊtrue��ʾ������Ϣ�󼴿��ͷ���Դ��
    // ���� ��true��ʾ���ͳɹ���false��ʾ����ʧ�ܡ�
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
            std::cout << "Network����ʧ�ܡ�" << std::endl;
            return false;
        }
    }

// ���� ��������Ϣ��
// ���� ���ޡ�
// ���� ��ָ����Ϣ��ָ�롣
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

    // ���� ���ر���Ϣ��
    // ���� ��ָ����Ϣ��ָ�롣
    // ���� ���ޡ�
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
    // ���� ����ѹ���������ת��Ϊ������ࡣ
// ���� ������ת����msgpack::object��
// ���� ��ָ��T��ָ�롣
    template<typename T>
    T* Convert(const msgpack::object& obj)
    {
        T* t = new T();
        obj.convert(*t);
        return t;
    }
}

