#pragma once
#include"../gateway/qcgateway.hpp"
#include"network.h"
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
        void client_callback(std::string topic, NetworkTool::ServerMessage emessage);

         void qryAccount();																				//查询账户资金
         void qryPosition();																				//查询持仓
         std::string GetExchangeName(std::string strSymbol);
         int  GetSymbolSize(std::string strSymbol);
         void connect();																					//连接


private:
    RpcClient*  m_client;
};

