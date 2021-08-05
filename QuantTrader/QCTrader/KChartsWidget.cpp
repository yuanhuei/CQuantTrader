#include "KChartsWidget.h"
#include"qcstructs.h"
#include<talib.h>
#include<ta_defs.h>
#include<math.h>
#include"utility.h"

class MyAxisTickerText : public QCPAxisTickerText
{
protected:
    virtual QVector<double> createTickVector(double tickStep, const QCPRange& range) Q_DECL_OVERRIDE
    {
        Q_UNUSED(tickStep)
            QVector<double> result;
        if (mTicks.isEmpty())
            return result;

        auto start = mTicks.lowerBound(range.lower);
        auto end = mTicks.upperBound(range.upper);
        if (start != mTicks.constBegin()) --start;
        if (end != mTicks.constEnd()) ++end;

        int count = cleanMantissa(std::distance(start, end) / double(mTickCount + 1e-10));

        auto it = start;
        while (it != end) {
            result.append(it.key());
            int step = count;
            if (step == 0) ++it;
            while (--step >= 0 && it != end)
                ++it;
        }

        return result;
    }
};
KChartsWidget::KChartsWidget(QWidget *parent, std::vector<BarData>* pBarData)
	: QWidget(parent)
{
    setWindowFlags(Qt::CustomizeWindowHint |
        Qt::WindowMinimizeButtonHint |
        Qt::WindowMaximizeButtonHint);

    setWindowFlags(Qt::Window);
	ui.setupUi(this);
	m_barData = pBarData;
    setUI(ui.widget);
}

KChartsWidget::~KChartsWidget()
{
}
void KChartsWidget::selectmMaAction(bool bChecked)
{
    //ui.widget->actionm
    if (maAction->isChecked())
    {
        graphMa5->setVisible(true);
        graphMa10->setVisible(true);
        graphMa20->setVisible(true);
        graphMa30->setVisible(true);

    }
    else
    {
        graphMa5->setVisible(false);
        graphMa10->setVisible(false);
        graphMa20->setVisible(false);
        graphMa30->setVisible(false);

    }
    ui.widget->replot();

}
void KChartsWidget::selectBollAction(bool bChecked)
{
    //ui.widget->actionm
    if (bollAction->isChecked())
    {
        graphBollup->setVisible(true);
        graphBolldown->setVisible(true);
        graphBollmid->setVisible(true);

    }
    else
    {
        graphBollup->setVisible(false);
        graphBolldown->setVisible(false);
        graphBollmid->setVisible(false);

    }
    ui.widget->replot();

}
void KChartsWidget::one_min_periodAction()
{
    updateWithPeriod(1);
}
void KChartsWidget::five_min_periodAction()
{
    updateWithPeriod(5);
}
void KChartsWidget::updateWithPeriod(int iMinute)
{
    QSharedPointer<QCPAxisTickerText> textTicker(new MyAxisTickerText);     // 文字轴
    //textTicker->setTickCount(10);
    //QCPDataContainer<QCPFinancialData> datas;
    //QVector<double> timeDatas, MA5Datas, MA10Datas, MA20Datas, MA30Datas,bollup,bolldown,bollmid;
    timeDatas.clear();
    MA5Datas.clear();
    MA10Datas.clear();
    MA20Datas.clear();
    MA30Datas.clear();
    bollup.clear();
    bolldown.clear();
    bollmid.clear();
    datas.clear();
    volumeNeg->data()->clear();// setData();
    volumePos->data()->clear();
    

    financial->data()->clear();
    graphBollup->data().data()->clear();
    graphBolldown->data().data()->clear();
    graphBollmid->data().data()->clear();
    graphMa5->data().data()->clear();
    graphMa10->data().data()->clear();
    graphMa20->data().data()->clear();
    graphMa30->data().data()->clear();


    std::vector<BarData> barData = Global_FUC::BarConvert(*m_barData, iMinute);
    if (m_barData != nullptr)
    {
        for (int i = 0; i < barData.size(); i++)
        {
            timeDatas.append(i);

            QCPFinancialData data;
            data.key = i;
            data.open = barData[i].open;// rawDatas.at(i).at(0);
            data.close = barData[i].close;// rawDatas.at(i).at(1);
            data.low = barData[i].low;// rawDatas.at(i).at(2);
            data.high = barData[i].high;// rawDatas.at(i).at(3);
            datas.add(data);

            textTicker->addTick(i, QString::fromStdString(barData[i].datetime));

            if (barData[i].open >= barData[i].close)
                volumePos->addData(i, barData[i].volume);
            else
                volumeNeg->addData(i, barData[i].volume);

        }
    }
    MA5Datas = sma(barData, 5);
    MA10Datas = sma(barData, 10);
    MA20Datas = sma(barData, 20);
    MA30Datas = sma(barData, 30);
    std::map<std::string, QVector<double>> mapBoll = boll(barData, 26, 2);
    bollup = mapBoll["boll_up"];
    bolldown = mapBoll["boll_down"];
    bollmid = mapBoll["boll_middle"];


    financial->data()->set(datas);
    graphBollup->setData(timeDatas, bollup);
    graphBolldown->setData(timeDatas, bolldown);
    graphBollmid->setData(timeDatas, bollmid);
    graphMa5->setData(timeDatas, MA5Datas);
    graphMa10->setData(timeDatas, MA10Datas);
    graphMa20->setData(timeDatas, MA20Datas);
    graphMa30->setData(timeDatas, MA30Datas);

    ui.widget->xAxis->setTicker(textTicker);
    volumeAxisRect->axis(QCPAxis::atBottom)->setTicker(textTicker);

    selectBollAction(true);
    selectBollAction(true);
    ui.widget->replot();

}
void KChartsWidget::setUI(QCustomPlot* customPlot)
{

    //添加右键菜
    QMenu* MainMenu = new QMenu(this);
    QAction* action_timeperiod = new QAction("timeperiod", MainMenu);
    QAction* action_index = new QAction("main_index", MainMenu);
    ui.widget->addAction(action_timeperiod);
    ui.widget->addAction(action_index);




    //子菜单
    QMenu* childMenu_timeperiod = new QMenu();
    //子菜单的 子项
    QAction* one_min_period = new QAction(childMenu_timeperiod);
    one_min_period->setText("1min");
    QAction* five_min_period = new QAction(childMenu_timeperiod);
    five_min_period->setText("5min");
    QList<QAction*> childActionList;
    childActionList << one_min_period\
        << five_min_period;
    childMenu_timeperiod->addActions(childActionList);
    //设置子菜单 归属opion
    action_timeperiod->setMenu(childMenu_timeperiod);
    //主菜单添加子菜单
    MainMenu->addMenu(childMenu_timeperiod);

    //子菜单
    QMenu* childMenu_index = new QMenu();
    //子菜单的 子项
    if(maAction==nullptr)
         maAction = new QAction(childMenu_index);
    maAction->setText("Ma");
    maAction->setCheckable(true);
    //maAction->che
    bollAction = new QAction(childMenu_index);
    bollAction->setText("Boll");
    bollAction->setCheckable(true);
    QList<QAction*> childActionListIndex;
    childActionListIndex << maAction\
        << bollAction;
    childMenu_index->addActions(childActionListIndex);
    //设置子菜单 归属opion
    action_index->setMenu(childMenu_index);
    //主菜单添加子菜单
    MainMenu->addMenu(childMenu_index);
    // 移动到当前鼠标所在未知
    //MainMenu->exec(QCursor::pos());
    maAction->setChecked(true);
    bollAction->setChecked(true);

    //右键处理事件
    connect(maAction, SIGNAL(toggled(bool)), this, SLOT(selectmMaAction(bool)));
    connect(bollAction, SIGNAL(toggled(bool)), this, SLOT(selectBollAction(bool)));
    connect(one_min_period, SIGNAL(triggered()), this, SLOT(one_min_periodAction()));
    connect(five_min_period, SIGNAL(triggered()), this, SLOT(five_min_periodAction()));


    const QColor BrushPositive("#ec0000");
    const QColor PenPositive("#8a0000");
    const QColor BrushNegative("#00da3c");
    const QColor PenNegative("#008f28");


    QSharedPointer<QCPAxisTickerText> textTicker(new MyAxisTickerText);      // 文字轴
    textTicker->setTickCount(10);
    //QCPDataContainer<QCPFinancialData> datas;
    //QVector<double> timeDatas, MA5Datas, MA10Datas, MA20Datas, MA30Datas,bollup,bolldown,bollmid;

    std::vector<BarData> barData=Global_FUC::BarConvert(*m_barData,5);
    if (m_barData != nullptr)
    {
        for (int i = 0; i < barData.size(); i++ )
        {
            timeDatas.append(i);

            QCPFinancialData data;
            data.key = i;
            data.open = barData[i].open;// rawDatas.at(i).at(0);
            data.close = barData[i].close;// rawDatas.at(i).at(1);
            data.low = barData[i].low;// rawDatas.at(i).at(2);
            data.high = barData[i].high;// rawDatas.at(i).at(3);
            datas.add(data);

            textTicker->addTick(i,  QString::fromStdString(barData[i].datetime));
        }
    }
    MA5Datas = sma(barData, 5);
    MA10Datas = sma(barData, 10);
    MA20Datas = sma(barData, 20);
    MA30Datas = sma(barData, 30);
    std::map<std::string, QVector<double>> mapBoll = boll(barData,26, 2);
    bollup = mapBoll["boll_up"];
    bolldown = mapBoll["boll_down"];
    bollmid = mapBoll["boll_middle"];

    int n = barData.size();
    financial = new QCPFinancial(customPlot->xAxis, customPlot->yAxis);
    financial->setName("K");
    financial->setBrushPositive(BrushPositive);
    financial->setPenPositive(PenPositive);
    financial->setBrushNegative(BrushNegative);
    financial->setPenNegative(PenNegative);
    financial->data()->set(datas);

    const QVector<QColor> ColorOptions = {
        "#c23531", "#2f4554", "#61a0a8", "#d48265"
    };
    graphBollup = customPlot->addGraph();
    graphBollup->setName("Boll");
    graphBollup->setData(timeDatas, bollup);
    graphBollup->setPen(ColorOptions.at(0));
    graphBolldown = customPlot->addGraph();
    graphBolldown->setName("Bolldown");
    graphBolldown->setData(timeDatas, bolldown);
    graphBolldown->setPen(ColorOptions.at(0));
    graphBollmid = customPlot->addGraph();
    graphBollmid->setName("Bollmid");
    graphBollmid->setData(timeDatas, bollmid);
    graphBollmid->setPen(ColorOptions.at(0));

    graphMa5 = customPlot->addGraph();
    graphMa5->setName("MA5");
    graphMa5->setData(timeDatas, MA5Datas);
    graphMa5->setPen(ColorOptions.at(0));
    //graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(ColorOptions.at(0), 2), QBrush(Qt::white), 8));
    //graph->setSmooth(true);

    graphMa10 = customPlot->addGraph();
    graphMa10->setName("MA10");
    graphMa10->setData(timeDatas, MA10Datas);
    graphMa10->setPen(ColorOptions.at(1));
    //graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(ColorOptions.at(1), 2), QBrush(Qt::white), 8));
    //graph->setSmooth(true);

    graphMa20 = customPlot->addGraph();
    graphMa20->setName("MA20");
    graphMa20->setData(timeDatas, MA20Datas);
    graphMa20->setPen(ColorOptions.at(2));
    //graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(ColorOptions.at(2), 2), QBrush(Qt::white), 8));
    //graph->setSmooth(true);

    graphMa30 = customPlot->addGraph();
    graphMa30->setName("MA30");
    graphMa30->setData(timeDatas, MA30Datas);
    graphMa30->setPen(ColorOptions.at(3));
    //graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(ColorOptions.at(3), 2), QBrush(Qt::white), 8));
    //graph->setSmooth(true);

    customPlot->xAxis->setTicker(textTicker);
    customPlot->rescaleAxes();
    customPlot->xAxis->scaleRange(1.05, customPlot->xAxis->range().center());
    customPlot->yAxis->scaleRange(1.05, customPlot->yAxis->range().center());
    //customPlot->axisRect()->addAxis(QCPAxis::atLeft)->setRange(0,100);
   // customPlot->axisRect()->addAxis(QCPAxis::atTop);
    //customPlot->ax
    customPlot->legend->setVisible(true);
    ui.widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    // create bottom axis rect for volume bar chart:
    volumeAxisRect = new QCPAxisRect(customPlot);
    customPlot->plotLayout()->addElement(1, 0, volumeAxisRect);
    volumeAxisRect->setMaximumSize(QSize(QWIDGETSIZE_MAX, 100));
    volumeAxisRect->axis(QCPAxis::atBottom)->setLayer("axes");
    volumeAxisRect->axis(QCPAxis::atBottom)->grid()->setLayer("grid");
    // bring bottom and main axis rect closer together:
    customPlot->plotLayout()->setRowSpacing(0);
    volumeAxisRect->setAutoMargins(QCP::msLeft | QCP::msRight | QCP::msBottom);
    volumeAxisRect->setMargins(QMargins(0, 0, 0, 0));
    // create two bar plottables, for positive (green) and negative (red) volume bars:
    customPlot->setAutoAddPlottableToLegend(false);
    volumePos = new QCPBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
    volumeNeg = new QCPBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
    //QCPDataContainer<QCPBarsData> volumePos_datas, volumeNeg_datas;
   // QDate date=QDate(barData[0].date
    QDateTime start = QDateTime::fromString(QString::fromStdString(barData[0].datetime), "yy-MM-dd hh:mm:ss");// QDateTime();// QDate(2014, 6, 11));
    start.setTimeSpec(Qt::UTC);
    double startTime = start.toTime_t();
    for (int i = 0; i < barData.size(); ++i)
    {
        if (barData[i].open >= barData[i].close)
            volumePos->addData(i,barData[i].volume);
        else
            volumeNeg->addData(i,barData[i].volume);
       // int v = barData[i].volume;// qrand() % 20000 + qrand() % 20000 + qrand() % 20000 - 10000 * 3;
        //(v < 0 ? volumeNeg : volumePos)->addData(startTime + 3600 * 5.0 * i, qAbs(v)); // add data to either volumeNeg or volumePos, depending on sign of v
    }
    volumePos->setWidth(1);
    volumePos->setPen(Qt::NoPen);
    volumePos->setBrush(QColor(100, 180, 110));
    volumeNeg->setWidth(1);
    volumeNeg->setPen(Qt::NoPen);
    volumeNeg->setBrush(QColor(180, 90, 90));
    //volumePos->data()->set();

    // interconnect x axis ranges of main and bottom axis rects:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), volumeAxisRect->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
    connect(volumeAxisRect->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis, SLOT(setRange(QCPRange)));
    // configure axes of both main and bottom axis rect:
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeSpec(Qt::UTC);
    dateTimeTicker->setDateTimeFormat("dd. MMMM");
    volumeAxisRect->axis(QCPAxis::atBottom)->setTicker(textTicker);// dateTimeTicker);
    //volumeAxisRect->axis(QCPAxis::atBottom)->setTickLabelRotation(15);
    customPlot->xAxis->setBasePen(Qt::NoPen);
    customPlot->xAxis->setTickLabels(false);
    customPlot->xAxis->setTicks(false); // only want vertical grid in main axis rect, so hide xAxis backbone, ticks, and labels
    //customPlot->xAxis->setTicker(dateTimeTicker);
    customPlot->rescaleAxes();
    customPlot->xAxis->scaleRange(1.025, customPlot->xAxis->range().center());
    customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());

    // make axis rects' left side line up:
    QCPMarginGroup* group = new QCPMarginGroup(customPlot);
    customPlot->axisRect()->setMarginGroup(QCP::msLeft | QCP::msRight, group);
    volumeAxisRect->setMarginGroup(QCP::msLeft | QCP::msRight, group);
}


QVector<double>  KChartsWidget::sma(const std::vector<BarData>& v, int dayCount)
{
    int    startIdx = 0;
    int    endIdx = v.size() - 1;
    double* inReal = new double[v.size()];// [100] ;
    int           optInTimePeriod = dayCount; /* From 2 to 100000 */
    int outBegIdx;
    int outNBElement;
    double        *outReal = new double[v.size()];
    QVector<double> result;
    for (int i = startIdx; i <=endIdx; i++)
    {
        inReal[i] = v[i].close;
    }

    int iReturn = TA_SMA(startIdx, endIdx, inReal, optInTimePeriod, &outBegIdx, &outNBElement, outReal);
    //if(iReturn!=0)
    //    print("失败");
    for (int i = 0; i < dayCount; i++)
    {
        result.append(qQNaN());

    }
    for (int i = 0; i < v.size(); i++)
    {
        result.append(outReal[i]);
    }
    delete[] inReal;
    delete[] outReal;
    return result;
}

std::map<std::string, QVector<double>> KChartsWidget::boll(const std::vector<BarData>& vBarData,int iWindow, int iDev)
{
    std::map<std::string, QVector<double>> mapBoll;
    QVector<double> bollup, bolldown, bollmid;
    int            startIdx = 0;
    int            endIdx = vBarData.size() - 1;
    //double        inReal[100];
    double* inReal = new double[vBarData.size()];// [100] ;
    int           optInTimePeriod = iWindow; /* From 2 to 100000 */
    double        optInNbDevUp = iDev; /* From TA_REAL_MIN to TA_REAL_MAX */
    double        optInNbDevDn = iDev; /* From TA_REAL_MIN to TA_REAL_MAX */
    TA_MAType     optInMAType = TA_MAType_SMA;
    int          outBegIdx;
    int          outNBElement;
    //double        outRealUpperBand[100];
    double* outRealUpperBand = new double[vBarData.size()];
    double* outRealMiddleBand = new double[vBarData.size()];
    double* outRealLowerBand = new double[vBarData.size()];

    //double        outRealMiddleBand[100];
    //double        outRealLowerBand[100];

    for (int i = 0; i < vBarData.size(); i++)
    {
        inReal[i] = vBarData[i].close;
    }

    TA_BBANDS(startIdx, endIdx, inReal, optInTimePeriod, optInNbDevDn,
        optInNbDevDn, optInMAType, &outBegIdx, &outNBElement, outRealUpperBand, outRealMiddleBand, outRealLowerBand);
    for (int i = 0; i < iWindow; i++)
    {
        bollup.append(qQNaN());
        bolldown.append(qQNaN());
        bollmid.append(qQNaN());

    }
    for (int i = 0; i < vBarData.size(); i++)
    {
        bollup.append(outRealUpperBand[i]);
        bolldown.append(outRealLowerBand[i]);
        bollmid.append(outRealMiddleBand[i]);

    }
    mapBoll["boll_up"] = bollup;
    mapBoll["boll_middle"] = bollmid;
    mapBoll["boll_down"] = bolldown;
    delete[] inReal;
    delete[]  outRealUpperBand, outRealMiddleBand, outRealLowerBand;
    return mapBoll;

}
