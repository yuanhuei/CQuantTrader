#pragma once
#ifndef RPCTESTDIALOG_H
#define RPCTESTDIALOG_H

#include <QWidget>
#include "ui_RpcTestDialog.h"
//nclude"rpc/rfc_frame.h"
class MainWindow;
class RpcClient;
class RpcServer;

class RpcTestDialog : public QWidget
{
	Q_OBJECT

public:
	RpcTestDialog(QWidget *parent = Q_NULLPTR);
	~RpcTestDialog();
	
	Ui::RpcTestDialog ui;
public:
	void write_log(std::string msg, std::string gateway_name);
private:
	RpcClient* m_rpcClient;
	RpcServer* m_rpcServer;
	//void write_log(std::string msg, std::string gateway_name);
	MainWindow* m_MainWindow;
private slots:
	void rpcserver_start();
	void rpcserver_stop();
	void rpcclient_start();
	void rpcclient_stop();
	void rpcserver_publish();
	void rpcclient_sendreq();

};
#endif
