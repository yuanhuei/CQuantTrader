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
	QVector<double> calculateMA(const QVector<QVector<double> > &v, int dayCount);
	void setUI(QCustomPlot* customPlot);
	QVector<double>  sma(const std::vector<BarData>& v, int dayCount);
	std::map<std::string, QVector<double>> boll(const std::vector<BarData>& v,int iWindow, int iDev);

private:
	Ui::KChartsWidget ui;
	std::vector<BarData>* m_barData;
	QAction* maAction=nullptr,*bollAction;
	QVector<double> timeDatas, MA5Datas, MA10Datas, MA20Datas, MA30Datas, bollup, bolldown, bollmid;
	QCPGraph* graphBollup, *graphBolldown, *graphBollmid, *graphMa5, *graphMa10, *graphMa20, *graphMa30;

private slots:
	void selectmMAction(int i);
	void selectBollAction(int i);

};
/*
class MyAxisTickerText : public QCPAxisTickerText
{
protected:
	virtual QVector<double> createTickVector(double tickStep, const QCPRange& range) Q_DECL_OVERRIDE;

};*/
