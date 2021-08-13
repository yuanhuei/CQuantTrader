#ifndef NETWORK_HPP
#define NETWORK_HPP

#include<zmq.h>
#include<string>
#include<cassert>
#include<iostream>

#include<zmq.h>
#include<msgpack.hpp>


namespace Message
{
    //��Ϣ����
    class  BaseMessage
    {
    public:

        MSGPACK_DEFINE(Type);

        //��Ϣ����
        int Type;

        //Ĭ�Ϲ��캯��
        BaseMessage()
        {
            Type = 0;
        }
    };

    //���Կͻ��˵���Ϣ
    class ClientMessage : public BaseMessage
    {
    public:

        MSGPACK_DEFINE(Type, Information);

        //��Ϣ
        std::string Information;

        //Ĭ�Ϲ��캯��
        ClientMessage()
        {
            Type = 1024;
        }
    };

    //���Է���˵���Ϣ
    class ServerMessage : public BaseMessage
    {
    public:

        MSGPACK_DEFINE(Type, Information);

        //��Ϣ
        std::vector<std::string> Information;

        //Ĭ�Ϲ��캯��
        ServerMessage()
        {
            Type = 2048;
        }
    };
};

namespace MsgTool
{
    class Msgpack
    {
    public:

        // ���� �����캯����
        // ���� ���ޡ�
        // ���� ���ޡ�
        Msgpack(void) { }

        // ���� ������������
        // ���� ���ޡ�
        // ���� ���ޡ�
        ~Msgpack(void) { }

        // ���� ��ѹ�����ݡ�
        // ���� ��Ҫѹ�������ݡ�
        // ���� ��true��ʾѹ���ɹ���
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
        }

        // ���� ��������ݡ�
        // ���� ��zmq��Ϣ�塣
        // ���� ������ָ�������Ϣ��ָ�롣
        Message::BaseMessage* Unpack(zmq_msg_t& msg)
        {
            try
            {
                int size = zmq_msg_size(&msg);
                if (size > 0)
                {
                    Release();
                    m_sbuf.write((char*)zmq_msg_data(&msg), size);
                    size_t offset = 0;
                    msgpack::zone z;
                    msgpack::object obj;

                    msgpack::object_handle oh = msgpack::unpack(m_sbuf.data(), m_sbuf.size());   // �����л���ʵ��
                    msgpack::object deserialized = oh.get();
                    //msgpack::unpack(m_sbuf.data(), m_sbuf.size(), &offset, &z, &obj);
                    return GetMessage(deserialized);
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
        inline msgpack::sbuffer& GetSbuf()
        {
            return m_sbuf;
        }

    private:

        //ѹ��/�������
        msgpack::sbuffer m_sbuf;


        // ���� ���ͷ���һ�ε�������Դ��
        // ���� ���ޡ�
        // ���� ���ޡ�
        void Release()
        {
            m_sbuf.clear();
            m_sbuf.release();
        }

        // ���� ����ȡ��Ϣ��
        // ���� ������ת����msgpack::object��
        // ���� ��ָ����Ϣ�����ָ�롣
        Message::BaseMessage* GetMessage(const msgpack::object& obj)
        {
            Message::BaseMessage bmessage;
            obj.convert(bmessage);
            switch (bmessage.Type)
            {
            case 1024:
                return Convert<Message::ClientMessage>(obj);
            case 2048:
                return Convert<Message::ServerMessage>(obj);
            default:
                return NULL;
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
    };

    //���繤����
    class Network
    {
    public:

        // ���� �����캯����
        // ���� ���ޡ�
        // ���� ���ޡ�
        Network() : m_socket(NULL)
        {
            Context = zmq_ctx_new();
        }

        // ���� ������������
        // ���� ���ޡ�
        // ���� ���ޡ�
        ~Network()
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
        bool Init(int zmqType, const std::string& address)
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



    private:

        //ͨ��socket
        void* m_socket;

        //���绷��
        void* Context;

    private:

        // ���� ������socket��
        // ���� ��zmqType��ʾZMQ��ģʽ��address��ʾsocket�󶨻����ӵ�ַ��
        // ���� ��true��ʾ���óɹ���false��ʾ����ʧ�ܡ�
        bool SetSocket(int zmqType, const std::string& address)
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


    };

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
    bool SendMessage(Msgpack* msgpack, zmq::socket_t *socket_t, zmq::send_flags flags= zmq::send_flags::none,bool isRelease = true)
    {
        try
        {
            zmq_msg_t msg;
            //zmq_msg_init(&msg);
            int i, j;
            if (isRelease)
            {
                 i=zmq_msg_init_data(&msg, msgpack->GetSbuf().data(), msgpack->GetSbuf().size(), Release, msgpack);
            }
            else
            {
                 i=zmq_msg_init_data(&msg, msgpack->GetSbuf().data(), msgpack->GetSbuf().size(), 0, 0);
            }
             //j=zmq_msg_send(&msg, socket_t, int(flags));
             
            zmq::message_t msg_t(msgpack->GetSbuf().size());
            memcpy(msg_t.data(), &msg, msgpack->GetSbuf().size());
           //socket_t->send(msg_t,flags);
            size_t tSize=socket_t->send((void*)&msg, msgpack->GetSbuf().size(),(int) flags);
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
    zmq_msg_t* ReceiveMessage(zmq::socket_t *socket_t, zmq::send_flags flags = zmq::send_flags::none)
    {
        zmq_msg_t* reply = NULL;
        try
        {
            reply = new zmq_msg_t();
            zmq_msg_init(reply);
            //zmq_msg_recv(reply, socket_t, int(flags));
            zmq::message_t reply_message;
           socket_t->recv(&reply_message,int(flags));
           *reply = *reply_message.handle();
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

};
#endif
