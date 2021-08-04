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

private:
	Ui::KChartsWidget ui;
	std::vector<BarData>* m_barData;

};
/*
class MyAxisTickerText : public QCPAxisTickerText
{
protected:
	virtual QVector<double> createTickVector(double tickStep, const QCPRange& range) Q_DECL_OVERRIDE;

};*/
