#include "RpcTestDialog.h"
#include"MainWindow.h"
#include"rpc/rfc_frame.h"
#include"rpc/network.h"

#define RPC_REP_ADDRESS "tcp://127.0.0.1:2014"
#define RPC_PUB_ADDRESS "tcp://127.0.0.1:4102"

RpcTestDialog::RpcTestDialog(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::CustomizeWindowHint |
		Qt::WindowMinimizeButtonHint |
		Qt::WindowMaximizeButtonHint);
	setWindowFlags(Qt::Window);

	ui.setupUi(this);
	m_MainWindow = (MainWindow*)parent;
	m_rpcClient = new RpcClient(this);
	m_rpcServer = new RpcServer(this);
}

RpcTestDialog::~RpcTestDialog()
{
	delete m_rpcClient;
	delete m_rpcServer;
}

void RpcTestDialog::rpcserver_start()
{
	m_rpcServer->start(RPC_REP_ADDRESS, RPC_PUB_ADDRESS);
	ui.pushButton->setDisabled(true);
	ui.pushButton_3->setEnabled(true);
}
void RpcTestDialog::rpcserver_stop()
{
	m_rpcServer->stop();
	ui.pushButton->setEnabled(true);
	ui.pushButton_3->setDisabled(true);
	m_rpcServer->join();


}
void RpcTestDialog::rpcclient_start()
{
	m_rpcClient->start(RPC_REP_ADDRESS, RPC_PUB_ADDRESS);
	ui.pushButton_2->setDisabled(true);
	ui.pushButton_4->setEnabled(true);
}
void RpcTestDialog::rpcclient_stop()
{
	m_rpcClient->stop();
	ui.pushButton_2->setEnabled(true);
	ui.pushButton_4->setDisabled(true);
	m_rpcClient->join();
}
void RpcTestDialog::rpcserver_publish()
{
	QString strInput = ui.textEdit_2->toPlainText();
	if(strInput.size()>0)
		m_rpcServer->publish(strInput.toStdString());
}
void RpcTestDialog::rpcclient_sendreq()
{
	/*
	QString strInput = ui.textEdit_3->toPlainText();
	if (strInput.size() > 0)
		m_rpcClient->sendRequest(strInput.toStdString());
    */
	//using namespace NetworkTool;
	
	//int i = 10;
	NetworkTool::ServerMessage returnMessage;
	std::tuple<int, int> inputPara(10,10);
	NetworkTool::MethodCallMessage<std::tuple<int, int>> callMethod("caculate_x_y", inputPara);

	m_rpcClient->call_server(callMethod, returnMessage);
	//if (returnMessage.strReturn == "NO_NULL")
	m_rpcClient->outputString("Caculation resule is:" + std::to_string(returnMessage.iReturn) + "\n");
	//else
		//write_log("·¢ËÍ½ÓÊÜ´íÎó","rpc");
	/*
	std::vector <ClientMessage> vMessage;
	
	ClientMessage cFuncName, cFuncPara;
	cFuncName.func_name = "calculate_x_y";
	vMessage.push_back(cFuncName);

	cFuncPara.iPut =10 ;
	vMessage.push_back(cFuncPara);
	
	m_rpcClient->call_server(vMessage, returnMessage);
	m_rpcClient->outputString("Caculation resule is:"+ returnMessage.iReturn);
	*/
	
}
void RpcTestDialog:: write_log(std::string msg, std::string gateway_name)
{
	m_MainWindow->write_log(msg, gateway_name);

}