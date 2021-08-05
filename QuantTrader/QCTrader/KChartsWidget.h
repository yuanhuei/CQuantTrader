#pragma once

#include <QWidget>
#include "ui_KChartsWidget.h"
class BarData;

class KChartsWidget : public QWidget
{
	Q_OBJECT

public:
	KChartsWidget(QWidget *parent = Q_NULLPTR, std::vector<BarData>* pBarData=nullptr);
	~KChartsWidget();
	void setUI(QCustomPlot* customPlot);
	QVector<double>  sma(const std::vector<BarData>& v, int dayCount);
	std::map<std::string, QVector<double>> boll(const std::vector<BarData>& v,int iWindow, int iDev);

private:
	Ui::KChartsWidget ui;
	std::vector<BarData>* m_barData;
	QAction* maAction=nullptr,*bollAction;
	QVector<double> timeDatas, MA5Datas, MA10Datas, MA20Datas, MA30Datas, bollup, bolldown, bollmid;
	QCPGraph* graphBollup, *graphBolldown, *graphBollmid, *graphMa5, *graphMa10, *graphMa20, *graphMa30;
	QCPFinancial* financial;
	QCPBars* volumePos, * volumeNeg;
	QCPDataContainer<QCPFinancialData> datas;
	QSharedPointer<QCPAxisTickerText> textTicker;
	QCPAxisRect* volumeAxisRect;

	void updateWithPeriod(int iMinute);

private slots:
	void selectmMaAction(bool bChecked);
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
