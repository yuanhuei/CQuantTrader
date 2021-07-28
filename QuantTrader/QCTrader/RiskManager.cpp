#include "RiskManager.h"
#include"risk_manager/RiskManagerEngine.h"
#include"MainWindow.h"


RiskManager::RiskManager(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::CustomizeWindowHint |
		Qt::WindowMinimizeButtonHint |
		Qt::WindowMaximizeButtonHint);
	setWindowFlags(Qt::Window);

	ui.setupUi(this);
	m_mainwindow = (MainWindow*)parent;
	m_riskEngine = m_mainwindow->m_riskmanagerEngine;
	initUI();
}

RiskManager::~RiskManager()
{
}

void RiskManager::initUI()
{
	ui.comboBox->blockSignals(true);
	if (m_riskEngine->active == true)
		ui.comboBox->setCurrentIndex(0);
	else
		ui.comboBox->setCurrentIndex(1);
	ui.comboBox->blockSignals(false);

	ui.spinBox_orderCancelLimit->setValue(m_riskEngine->orderCancelLimit);
	ui.spinBox_orderFlowClear->setValue(m_riskEngine->orderFlowClear);
	ui.spinBox_orderFlowLimit->setValue(m_riskEngine->orderFlowLimit);
	ui.spinBox_orderSizeLimit->setValue(m_riskEngine->orderSizeLimit);
	ui.spinBox_tradeLimit->setValue(m_riskEngine->tradeLimit);
	ui.spinBox_workingOrderLimit->setValue(m_riskEngine->workingOrderLimit);

}
void RiskManager::saveButton_clicked()
{
	m_riskEngine->setOrderCancelLimit(ui.spinBox_orderCancelLimit->value());
	m_riskEngine->setOrderFlowClearTime(ui.spinBox_orderFlowClear->value());
	m_riskEngine->setOrderFlowLimit(ui.spinBox_orderFlowLimit->value());
	m_riskEngine->setOrderSizeLimit(ui.spinBox_orderSizeLimit->value());
	m_riskEngine->setTradeLimit(ui.spinBox_tradeLimit->value());
	m_riskEngine->setWorkingOrderLimit(ui.spinBox_workingOrderLimit->value());

	m_riskEngine->saveSetting();
	this->close();

}

void RiskManager::riskStatus_changed()
{
	m_riskEngine->switchEngineStatus();
}