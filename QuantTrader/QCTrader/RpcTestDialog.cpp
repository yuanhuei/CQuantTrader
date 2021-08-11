#include "RpcTestDialog.h"
#include"MainWindow.h"
#include"rpc/rfc_frame.h"

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
}
void RpcTestDialog::rpcserver_publish()
{
	QString strInput = ui.textEdit_2->toPlainText();
	if(strInput.size()>0)
		m_rpcServer->publish(strInput.toStdString(),"");
}
void RpcTestDialog::rpcclient_sendreq()
{
	QString strInput = ui.textEdit_3->toPlainText();
	if (strInput.size() > 0)
		m_rpcClient->sendRequest(strInput.toStdString());
}
void RpcTestDialog:: write_log(std::string msg, std::string gateway_name)
{
	m_MainWindow->write_log(msg, gateway_name);

}