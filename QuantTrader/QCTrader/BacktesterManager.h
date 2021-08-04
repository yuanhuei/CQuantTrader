#pragma once

#include <QWidget>
#include "ui_BacktesterManager.h"
#include<map>
#include<string>
#include"MainWindow.h"
#include"KChartsWidget.h"

class BacktesterEngine;
class MainWindow;


class BacktesterManager : public QWidget
{
	Q_OBJECT

public:
	BacktesterManager(QWidget *parent = Q_NULLPTR);
	~BacktesterManager();

	void InitUI();

	BacktesterEngine* m_backtesterEngine=nullptr;
	std::map<std::string, std::map<std::string, float>>  m_ctaStrategyMap;
	QCPBars* m_barOverXAxis =nullptr;//x���ϵ���״ͼ
	QCPBars* m_barUnderXAxis = nullptr;//x���·�����״ͼ

	MainWindow* m_mainwindow=nullptr;
	KChartsWidget* m_Kchart=nullptr;

	void UpdateLogTable(LogData data);
	void RegisterEvent();
	void ProcecssTesterFisnishedEvent(std::shared_ptr<Event>e);
signals:
	void UpdateTesterResultSignal();


private:
	Ui::BacktesterManager ui;

private slots:
	void startBacktest_clicked();
	void UpdateTesterResult();
	void kchart_clicked();
};
