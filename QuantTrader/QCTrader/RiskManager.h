#pragma once

#include <QWidget>
#include "ui_RiskManager.h"

class MainWindow;
class RiskManagerEngine;

class RiskManager : public QWidget
{
	Q_OBJECT

public:
	RiskManager(QWidget *parent = Q_NULLPTR);
	~RiskManager();

private:
	Ui::RiskManager ui;
	MainWindow* m_mainwindow;
	RiskManagerEngine* m_riskEngine;
	void initUI();

private slots:
	void saveButton_clicked();
	void riskStatus_changed();

};
