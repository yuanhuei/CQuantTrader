#pragma once

#include <QWidget>
#include "ui_RpcServiceDialog.h"
class MainWindow;

class RpcServiceDialog : public QWidget
{
	Q_OBJECT

public:
	RpcServiceDialog(QWidget *parent = Q_NULLPTR);
	~RpcServiceDialog();

private:
	Ui::RpcServiceDialog ui;
	MainWindow* m_mainwindow;

private slots:
	void rpcService_startButton_clicked();
	void rpcService_stopButton_clicked();
};
