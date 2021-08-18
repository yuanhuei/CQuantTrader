#include "RpcConnectDialog.h"
#include"MainWindow.h"
#include"rpc/RpcGateway.h"
RpcConnectDialog::RpcConnectDialog(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::CustomizeWindowHint |
		Qt::WindowMinimizeButtonHint |
		Qt::WindowMaximizeButtonHint);
	setWindowFlags(Qt::Window);

	ui.setupUi(this);
	m_mainwindow = (MainWindow*)parent;

}

RpcConnectDialog::~RpcConnectDialog()
{
}
void RpcConnectDialog::connect_button_clicked()
{
	m_mainwindow->m_rpcGateway->connect(ui.lineEdit->text().toStdString(), ui.lineEdit_2->text().toStdString());
}
