#pragma once

#include <QWidget>
#include "ui_KChartsWidget.h"
class BarData;
class Event_Trade;

class KChartsWidget : public QWidget
{
	Q_OBJECT

public:
	KChartsWidget(QWidget *parent = Q_NULLPTR, std::vector<BarData>* pBarData=nullptr,
		 std::map<std::string, std::shared_ptr<Event_Trade>> *pTradeMap=nullptr);
	~KChartsWidget();
	void setUI();
	void setRightMouseMenu();
	void setMainGraph();
	void setTradeGraph(int iMinutePeriod =1);

	QVector<double>  sma(const std::vector<BarData>& v, int dayCount);
	std::map<std::string, QVector<double>> boll(const std::vector<BarData>& v,int iWindow, int iDev);

private:
	Ui::KChartsWidget ui;
	std::vector<BarData>* m_barData;
	std::map <std::string, int > m_mapBarNumber;//根据datetime来获取是m_barData中的第几根bar
	std::map<std::string, std::shared_ptr<Event_Trade>>* m_TradeMap;

	QAction* maAction=nullptr,*bollAction;
	QVector<double> timeDatas, MA5Datas, MA10Datas, MA20Datas, MA30Datas, bollup, bolldown, bollmid;
	QCPGraph* graphBollup, *graphBolldown, *graphBollmid, *graphMa5, *graphMa10, *graphMa20, *graphMa30;
	QCPGraph* graphTrade_buy, *graphTrade_sell, *graphTrade_sellshort, *graphTrade_buycover;
	QVector<double> timeDatas_buy, timeDatas_sell, timeDatas_sellshort, timeDatas_buycover;
	QVector<double> priceDatas_buy, priceDatas_sell, priceDatas_sellshort, priceDatas_buycover;
	QCPBars* volumePos, * volumeNeg;
	QCPDataContainer<QCPFinancialData> datas;
	QSharedPointer<QCPAxisTickerText> textTicker;
	QCPAxisRect* volumeAxisRect;
	QCPFinancial* financial;

	void updateWithPeriod(int iMinute);

private slots:
	void selectMaAction(bool bChecked);
	void selectBollAction(bool bChecked);
	void one_min_periodAction();
	void five_min_periodAction();
	void fifth_min_periodAction();
	void thirty_min_periodAction();
	void sixty_min_periodAction();
	void define_min_periodAction();

};
/*
class MyAxisTickerText : public QCPAxisTickerText
{
protected:
	virtual QVector<double> createTickVector(double tickStep, const QCPRange& range) Q_DECL_OVERRIDE;

};*/
