#pragma once
#include"../gateway/qcgateway.hpp"
class RpcClient;

class RpcGateway :
    public QCGateway
{
    public:
        RpcGateway(EventEngine* eventengine, std::string gatewayname);
        ~RpcGateway();
        void connect(std::string req_address, std::string pub_address);
        void subscribe(SubscribeReq& subscribeReq);
        std::string sendOrder(OrderReq& req);
        void cancelOrder(CancelOrderReq& req);
        void query_all();
        void close();
        void client_callback(std::string topic, Event event);
private:
    RpcClient*  m_client;
};

