/********************************************************************************
** Form generated from reading UI file 'CTAStrategyManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTASTRATEGYMANAGER_H
#define UI_CTASTRATEGYMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTAStrategyManager
{
public:
    QGridLayout *gridLayout_5;
    QSplitter *splitter_2;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QFrame *frame_5;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QTableView *tableView;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QFrame *frame_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QTableView *tableView_2;
    QTableWidget *tableWidget_3;

    void setupUi(QWidget *CTAStrategyManager)
    {
        if (CTAStrategyManager->objectName().isEmpty())
            CTAStrategyManager->setObjectName(QString::fromUtf8("CTAStrategyManager"));
        CTAStrategyManager->resize(916, 543);
        gridLayout_5 = new QGridLayout(CTAStrategyManager);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        splitter_2 = new QSplitter(CTAStrategyManager);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 514));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMaximumSize(QSize(16777215, 200));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(frame_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_4->addLayout(horizontalLayout);


        gridLayout_4->addWidget(frame_3, 0, 0, 1, 1);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_5);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_7 = new QPushButton(frame_5);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(frame_5);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(frame_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_3->addWidget(pushButton_6);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tableView = new QTableView(frame_5);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        gridLayout_4->addWidget(frame_5, 1, 0, 1, 1);

        splitter_2->addWidget(frame);
        frame_2 = new QFrame(splitter_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(frame_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        frame_4 = new QFrame(splitter);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(129, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(frame_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(frame_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(frame_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        splitter->addWidget(frame_4);
        tableView_2 = new QTableView(splitter);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        splitter->addWidget(tableView_2);
        tableWidget_3 = new QTableWidget(splitter);
        if (tableWidget_3->columnCount() < 3)
            tableWidget_3->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        splitter->addWidget(tableWidget_3);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        splitter_2->addWidget(frame_2);

        gridLayout_5->addWidget(splitter_2, 0, 0, 1, 1);


        retranslateUi(CTAStrategyManager);
        QObject::connect(pushButton, SIGNAL(clicked()), CTAStrategyManager, SLOT(addStrategy_clicked()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), CTAStrategyManager, SLOT(startStrategy_clicked()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), CTAStrategyManager, SLOT(stopStrategy_clicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), CTAStrategyManager, SLOT(initAllStrategy_clicked()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), CTAStrategyManager, SLOT(startAllStrategy_clicked()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), CTAStrategyManager, SLOT(stopAllStrategy_clicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), CTAStrategyManager, SLOT(clearLog_clicked()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), CTAStrategyManager, SLOT(initStrategy_clicked()));
        QObject::connect(tableView, SIGNAL(clicked(QModelIndex)), CTAStrategyManager, SLOT(StrategyTable_clicked()));

        QMetaObject::connectSlotsByName(CTAStrategyManager);
    } // setupUi

    void retranslateUi(QWidget *CTAStrategyManager)
    {
        CTAStrategyManager->setWindowTitle(QApplication::translate("CTAStrategyManager", "CTAStrategyManager", nullptr));
        pushButton->setText(QApplication::translate("CTAStrategyManager", "\346\267\273\345\212\240\347\255\226\347\225\245", nullptr));
        pushButton_7->setText(QApplication::translate("CTAStrategyManager", "\345\210\235\345\247\213\345\214\226", nullptr));
        pushButton_8->setText(QApplication::translate("CTAStrategyManager", "\345\220\257\345\212\250", nullptr));
        pushButton_6->setText(QApplication::translate("CTAStrategyManager", "\345\201\234\346\255\242", nullptr));
        pushButton_3->setText(QApplication::translate("CTAStrategyManager", "\345\205\250\351\203\250\345\210\235\345\247\213\345\214\226", nullptr));
        pushButton_5->setText(QApplication::translate("CTAStrategyManager", "\345\205\250\351\203\250\345\220\257\345\212\250", nullptr));
        pushButton_4->setText(QApplication::translate("CTAStrategyManager", "\345\205\250\351\203\250\345\201\234\346\255\242", nullptr));
        pushButton_2->setText(QApplication::translate("CTAStrategyManager", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CTAStrategyManager", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CTAStrategyManager", "\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CTAStrategyManager", "\346\216\245\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTAStrategyManager: public Ui_CTAStrategyManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTASTRATEGYMANAGER_H
