#include "RpcServiceDialog.h"
#include"MainWindow.h"
#include"rpc/RpcEngine.h"

RpcServiceDialog::RpcServiceDialog(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::CustomizeWindowHint |
		Qt::WindowMinimizeButtonHint |
		Qt::WindowMaximizeButtonHint);
	setWindowFlags(Qt::Window);

	ui.setupUi(this);
	m_mainwindow = (MainWindow*)parent;
}

RpcServiceDialog::~RpcServiceDialog()
{
}

void RpcServiceDialog::rpcService_startButton_clicked()
{
	m_mainwindow->m_rpcEngine->start(ui.lineEdit->text().toStdString(),ui.lineEdit_2->text().toStdString());
}
void RpcServiceDialog::rpcService_stopButton_clicked()
{
	m_mainwindow->m_rpcEngine->stop();
}
