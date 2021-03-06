#include "CTAStrategyManager.h"

#include <string>  
#include <json/json.h>
#include <iostream>  
#include <fstream>  
#include"utility.h"
#include<qnamespace.h>
#include"./cta_strategy/StrategyTemplate.h"
#include"./cta_strategy/CtaEngine.h"

CTAStrategyManager::CTAStrategyManager(QWidget* parent)
	: QWidget(parent, Qt::WindowMinMaxButtonsHint)
{
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	//setWindowModality(Qt::NonModal);
	setWindowFlags(Qt::Window);

	//setWindowFlags(Qt::CustomizeWindowHint |
	//	Qt::WindowMinimizeButtonHint |
	//	Qt::WindowMaximizeButtonHint);

	ui.setupUi(this);
	m_mainwindow = (MainWindow*)parent;
	m_ctaEngine = m_mainwindow->m_ctaEngine;
	InitUI();

	connect(this, SIGNAL(UpdateStopOrderTableSignal()), this, SLOT(UpdateStopOrderTable()));
	m_mainwindow->m_eventengine->RegEvent(EVENT_STOP_ORDER, std::bind(&CTAStrategyManager::ProcecssStopOrderEvent, this, std::placeholders::_1));


}

CTAStrategyManager::~CTAStrategyManager()
{
}
void CTAStrategyManager::ProcecssStopOrderEvent(std::shared_ptr<Event>e)
{
	emit UpdateStopOrderTableSignal();

}

void CTAStrategyManager::UpdateStopOrderTable()
{
	m_StopOrderTableModel->clear();
	m_ctaEngine->m_stop_order_mtx.lock();
	std::map<std::string, std::shared_ptr<Event_StopOrder>>::iterator iter= m_ctaEngine->m_stop_order_map.begin();
	int i = 0;
	for (iter; iter != m_ctaEngine->m_stop_order_map.end(); iter++)
	{
		std::shared_ptr<Event_StopOrder>ptr_StopOrder = iter->second;

		m_StopOrderTableModel->setItem(i, 0, new QStandardItem(str2qstr_new(ptr_StopOrder->orderID)));
		m_StopOrderTableModel->setItem(i, 1, new QStandardItem(""));
		m_StopOrderTableModel->setItem(i, 2, new QStandardItem(str2qstr_new(ptr_StopOrder->symbol + "." + ptr_StopOrder->exchange)));
		m_StopOrderTableModel->setItem(i, 3, new QStandardItem(str2qstr_new(ptr_StopOrder->direction)));
		m_StopOrderTableModel->setItem(i, 4, new QStandardItem(str2qstr_new(ptr_StopOrder->offset)));
		m_StopOrderTableModel->setItem(i, 5, new QStandardItem(QString::number(ptr_StopOrder->price)));
		m_StopOrderTableModel->setItem(i, 6, new QStandardItem(QString::number(ptr_StopOrder->totalVolume)));
		m_StopOrderTableModel->setItem(i, 7, new QStandardItem(str2qstr_new((ptr_StopOrder->status))));
		m_StopOrderTableModel->setItem(i, 8, new QStandardItem(""));
		m_StopOrderTableModel->setItem(i, 9, new QStandardItem(str2qstr_new(ptr_StopOrder->strategyName)));
		i++;

	}
	m_ctaEngine->m_stop_order_mtx.unlock();
	return;

}
void CTAStrategyManager::updatePositionTable()
{
	m_PositionTableModel->clear();
	std::map<std::string, StrategyTemplate*>::iterator iter;
	int i = 0;
	for (iter = m_ctaEngine->m_strategymap.begin(); iter != m_ctaEngine->m_strategymap.end(); iter++)
	{
		m_PositionTableModel->setItem(i, 0, new QStandardItem(QString::fromStdString(iter->first)));
		m_PositionTableModel->setItem(i, 1, new QStandardItem(QString::fromStdString(iter->first)));
		m_PositionTableModel->setItem(i, 2, new QStandardItem(QString::fromStdString(std::to_string(iter->second->getpos()))));

		i++;
	}

}
void CTAStrategyManager::updateTradelistTable()
{
	m_TradeListTableModel->clear();
	std::map<std::string, StrategyTemplate*>::iterator iter;
	int i = 0;
	for (iter = m_ctaEngine->m_strategymap.begin(); iter != m_ctaEngine->m_strategymap.end(); iter++)
	{
		int j;
		for (j = 0; j < iter->second->m_tradelist.size(); j++)
		{
			Event_Trade* pTrade = &iter->second->m_tradelist[j];
			m_TradeListTableModel->setItem(i + j, 0, new QStandardItem(QString::fromStdString(iter->first)));
			m_TradeListTableModel->setItem(i + j, 1, new QStandardItem(QString::fromStdString(pTrade->tradeID)));
			m_TradeListTableModel->setItem(i + j, 2, new QStandardItem(QString::fromStdString(pTrade->orderID)));
			m_TradeListTableModel->setItem(i + j, 3, new QStandardItem(QString::fromStdString(pTrade->symbol)));
			m_TradeListTableModel->setItem(i + j, 4, new QStandardItem(QString::fromStdString(pTrade->exchange)));
			m_TradeListTableModel->setItem(i + j, 5, new QStandardItem(QString::fromStdString(pTrade->direction)));
			m_TradeListTableModel->setItem(i + j, 6, new QStandardItem(QString::fromStdString(pTrade->offset)));
			m_TradeListTableModel->setItem(i + j, 7, new QStandardItem(QString::fromStdString(std::to_string(pTrade->price))));
			m_TradeListTableModel->setItem(i + j, 8, new QStandardItem(QString::fromStdString(std::to_string(pTrade->volume))));
			m_TradeListTableModel->setItem(i + j, 9, new QStandardItem(QString::fromStdString(pTrade->tradeTime)));

		}
		i = i + j;

	}


}

void CTAStrategyManager::InitUI()
{
	//????????????????
	//ReadStrategyConfFileJson();

	m_ctaEngine->writeCtaLog("????????????????????");
	
	//??????????????
	m_StrategyConf = new QStandardItemModel;
	QStringList StrategyConfHeader;
	StrategyConfHeader << str2qstr_new("??????") << str2qstr_new("????") << str2qstr_new("????????")<< str2qstr_new("????");
	m_StrategyConf->setHorizontalHeaderLabels(StrategyConfHeader);
	ui.tableView->setModel(m_StrategyConf);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	//ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //????????????  
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection); //??????????????????????????????  
	ui.tableView->setAlternatingRowColors(true);

	//??????????????????????????????????
	std::map<std::string, std::map<std::string, float>>::iterator it;
	int i = 0;
	for (it = m_ctaEngine->m_strategyConfigInfo_map.begin(); it != m_ctaEngine->m_strategyConfigInfo_map.end(); it++)
	{
		QString strStrategy = QString::fromStdString(it->first).section("_",0,0);
		QString strSymbol = QString::fromStdString(it->first).section("_", 1, 1);
		QString strClassname = QString::fromStdString(it->first).section("_", 2, 2);
		
		m_StrategyConf->setItem(i, 0, new QStandardItem(strStrategy));
		m_StrategyConf->setItem(i, 1, new QStandardItem(strSymbol));
		m_StrategyConf->setItem(i, 2, new QStandardItem(strClassname));
		m_StrategyConf->setItem(i, 3, new QStandardItem(str2qstr_new("????????")));
		i++;


		ui.comboBox->addItem(strStrategy+" "+ strSymbol);

	}
	ui.pushButton->setDisabled(true);//????????

	//????????????
	m_StopOrderTableModel =new QStandardItemModel;
	QStringList StopOrderTableHeader;
	StopOrderTableHeader << str2qstr_new("??????????") << str2qstr_new("??????????") << str2qstr_new("????????") << str2qstr_new("????") << str2qstr_new("????") << str2qstr_new("????") << str2qstr_new("????") << str2qstr_new("????") << str2qstr_new("????") << str2qstr_new("??????");
	m_StopOrderTableModel->setHorizontalHeaderLabels(StopOrderTableHeader);
	ui.tableView_2->setModel(m_StopOrderTableModel);
	ui.tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	//ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);  //????????????  
	ui.tableView_2->setSelectionMode(QAbstractItemView::SingleSelection); //??????????????????????????????  
	ui.tableView_2->setAlternatingRowColors(true);

	//??????????????
	m_PositionTableModel = new QStandardItemModel;
	QStringList positionTableHeader;
	positionTableHeader << str2qstr_new("????????") << str2qstr_new("????????") << str2qstr_new("????????") << str2qstr_new("????????") << str2qstr_new("????????") << str2qstr_new("??????") << str2qstr_new("??????") << str2qstr_new("????????") ;
	m_PositionTableModel->setHorizontalHeaderLabels(positionTableHeader);
	ui.tableView_3->setModel(m_PositionTableModel);
	ui.tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	//ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView_3->setSelectionBehavior(QAbstractItemView::SelectRows);  //????????????  
	ui.tableView_3->setSelectionMode(QAbstractItemView::SingleSelection); //??????????????????????????????  
	ui.tableView_3->setAlternatingRowColors(true);
	std::map<std::string, StrategyTemplate*>::iterator iter;
	i = 0;
	for (iter = m_ctaEngine->m_strategymap.begin(); iter != m_ctaEngine->m_strategymap.end(); iter++)
	{
		m_PositionTableModel->setItem(i,0,new QStandardItem(QString::fromStdString(iter->first)));
		m_PositionTableModel->setItem(i, 1, new QStandardItem(QString::fromStdString(iter->first)));
		m_PositionTableModel->setItem(i, 2, new QStandardItem(QString::fromStdString(std::to_string(iter->second->getpos()))));



		i++;

	}

	//??????????????
	m_TradeListTableModel = new QStandardItemModel;
	QStringList tradelistTableHeader;
	tradelistTableHeader << str2qstr_new("????????") << str2qstr_new("??????") << str2qstr_new("??????") << str2qstr_new("????") << str2qstr_new("??????") << str2qstr_new("????") << str2qstr_new("????") << str2qstr_new("????") << str2qstr_new("????") << str2qstr_new("????");
	m_TradeListTableModel->setHorizontalHeaderLabels(tradelistTableHeader);
	ui.tableView_4->setModel(m_TradeListTableModel);
	ui.tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	//ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableView_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView_4->setSelectionBehavior(QAbstractItemView::SelectRows);  //????????????  
	ui.tableView_4->setSelectionMode(QAbstractItemView::SingleSelection); //??????????????????????????????  
	ui.tableView_4->setAlternatingRowColors(true);
	i = 0;
	for (iter = m_ctaEngine->m_strategymap.begin(); iter != m_ctaEngine->m_strategymap.end(); iter++)
	{
		int j;
		for (j = 0; j < iter->second->m_tradelist.size(); j++)
		{
			Event_Trade* pTrade = &iter->second->m_tradelist[j];
			m_TradeListTableModel->setItem(i+j, 0, new QStandardItem(QString::fromStdString(iter->first)));
			m_TradeListTableModel->setItem(i+j, 1, new QStandardItem(QString::fromStdString(pTrade->tradeID)));
			m_TradeListTableModel->setItem(i + j, 2, new QStandardItem(QString::fromStdString(pTrade->orderID)));
			m_TradeListTableModel->setItem(i + j, 3, new QStandardItem(QString::fromStdString(pTrade->symbol)));
			m_TradeListTableModel->setItem(i + j, 4, new QStandardItem(QString::fromStdString(pTrade->exchange)));
			m_TradeListTableModel->setItem(i + j, 5, new QStandardItem(QString::fromStdString(pTrade->direction)));
			m_TradeListTableModel->setItem(i + j, 6, new QStandardItem(QString::fromStdString(pTrade->offset)));
			m_TradeListTableModel->setItem(i + j, 7, new QStandardItem(QString::fromStdString(std::to_string(pTrade->price))));
			m_TradeListTableModel->setItem(i + j, 8, new QStandardItem(QString::fromStdString(std::to_string(pTrade->volume))));
			m_TradeListTableModel->setItem(i + j, 9, new QStandardItem(QString::fromStdString(pTrade->tradeTime)));

		}
		i=i+j;

	}

}
void CTAStrategyManager::addStrategy_clicked()
{
	QString strCurrentStrategy = ui.comboBox->currentText().section("__", 0, 0);
	QString strCurrentSymbol = ui.comboBox->currentText().section("__", 1, 1);

	for (int i = 0; i < m_StrategyConf->rowCount(); i++)
	{
		QString str = m_StrategyConf->item(i, 0)->text() + "__" + m_StrategyConf->item(i, 1)->text();
		if (str == ui.comboBox->currentText())//????????????????????????
			return;
		
	}
	int i = m_StrategyConf->rowCount();
	m_StrategyConf->setItem(i, 0, new QStandardItem(strCurrentStrategy));
	m_StrategyConf->setItem(i, 1, new QStandardItem(strCurrentSymbol));
	m_StrategyConf->setItem(i, 2, new QStandardItem(str2qstr_new("????????")));


}

//??????????
void CTAStrategyManager::initStrategy_clicked()
{
	//?????????????? ????????????????????
	int row = ui.tableView->currentIndex().row();
	QModelIndex index = m_StrategyConf->index(row, 0);
	std::string strStrategyName = m_StrategyConf->data(index).toString().toStdString();
	index = m_StrategyConf->index(row, 1);
	std::string strSymbolName = m_StrategyConf->data(index).toString().toStdString();
	index = m_StrategyConf->index(row, 2);
	std::string strClassName = m_StrategyConf->data(index).toString().toStdString();

	m_ctaEngine->initStrategy(strStrategyName + "__" + strSymbolName+"__"+ strClassName);//????????????????????????????????????????????

}

void CTAStrategyManager::StrategyTable_clicked()
{
	//int m_StrategyTableRowSelected = ui.tableView->currentIndex().row();
	//?????????????? ????????????????????

}
//????????
void CTAStrategyManager::startStrategy_cliced()
{
	//?????????????? ????????????????????
	int row = ui.tableView->currentIndex().row();
	QModelIndex index = m_StrategyConf->index(row, 0);
	std::string strStrategyName = m_StrategyConf->data(index).toString().toStdString();
	index = m_StrategyConf->index(row, 1);
	std::string strSymbolName = m_StrategyConf->data(index).toString().toStdString();
	index = m_StrategyConf->index(row, 2);
	std::string strClassName = m_StrategyConf->data(index).toString().toStdString();

	m_ctaEngine->startStrategy(strStrategyName + "__" + strSymbolName + "__" + strClassName);

}
//????????
void CTAStrategyManager::stopStragegy_clicked()
{
	//?????????????? ????????????????????
	int row = ui.tableView->currentIndex().row();
	QModelIndex index = m_StrategyConf->index(row, 0);
	std::string strStrategyName = m_StrategyConf->data(index).toString().toStdString();
	index = m_StrategyConf->index(row, 1);
	std::string strSymbolName = m_StrategyConf->data(index).toString().toStdString();
	index = m_StrategyConf->index(row, 2);
	std::string strClassName = m_StrategyConf->data(index).toString().toStdString();

	m_ctaEngine->stopStrategy(strStrategyName + "__" + strSymbolName + "__" + strClassName);
}
//????????????
void CTAStrategyManager::startAllStrategy_clicked()
{
	m_ctaEngine->startallStrategy();
}
//????????????
void CTAStrategyManager::stopAllStrategy_clicked() 
{
	m_ctaEngine->stopallStrategy();
}
//????????????
void CTAStrategyManager::clearLog()
{
	ui.tableWidget_3->clear();
}

//????????????
void CTAStrategyManager::UpdateLogTable(LogData data)
{
	//LogData data;
	//data.gatewayname = "CTP";
	//data.msg = msg;
	//data.logTime= Utils::getCurrentSystemTime();
	
	int rowCount = ui.tableWidget_3->rowCount();
	ui.tableWidget_3->insertRow(rowCount);
	ui.tableWidget_3->setItem(rowCount, 0, new QTableWidgetItem(str2qstr_new(data.logTime)));
	ui.tableWidget_3->setItem(rowCount, 1, new QTableWidgetItem(str2qstr_new(data.msg)));
	ui.tableWidget_3->setItem(rowCount, 2, new QTableWidgetItem(str2qstr_new(data.gatewayname)));
}
/*
void CTAStrategyManager::pushLogData(std::string msg)
{
	
	LogData data;
	data.gatewayname = "CTP";
	data.msg = msg;
	data.logTime= Utils::getCurrentSystemTime();
	this->UpdateLogTable(data);

}*/