#pragma once

#include <QWidget>
#include "ui_RpcConnectDialog.h"
class MainWindow;

class RpcConnectDialog : public QWidget
{
	Q_OBJECT

public:
	RpcConnectDialog(QWidget *parent = Q_NULLPTR);
	~RpcConnectDialog();

private:
	Ui::RpcConnectDialog ui;
	MainWindow* m_mainwindow;

private slots:
	void connect_button_clicked();
};
