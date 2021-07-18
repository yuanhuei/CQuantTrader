/********************************************************************************
** Form generated from reading UI file 'QCTrader.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCTRADER_H
#define UI_QCTRADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QCTraderClass
{
public:
    QAction *actionCTP;
    QAction *actionQuit;
    QAction *actionabout;
    QAction *actionCTACeLue;
    QAction *actionCTAHuiCe;
    QAction *actiondatamanager;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QTableView *tableView_2;
    QGroupBox *groupBox_3;
    QTableView *tableView_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_4;
    QTableView *tableView_4;
    QGroupBox *groupBox_5;
    QTableView *tableView_5;
    QGroupBox *groupBox_6;
    QTableView *tableView_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QCTraderClass)
    {
        if (QCTraderClass->objectName().isEmpty())
            QCTraderClass->setObjectName(QString::fromUtf8("QCTraderClass"));
        QCTraderClass->resize(951, 534);
        actionCTP = new QAction(QCTraderClass);
        actionCTP->setObjectName(QString::fromUtf8("actionCTP"));
        actionQuit = new QAction(QCTraderClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionabout = new QAction(QCTraderClass);
        actionabout->setObjectName(QString::fromUtf8("actionabout"));
        actionCTACeLue = new QAction(QCTraderClass);
        actionCTACeLue->setObjectName(QString::fromUtf8("actionCTACeLue"));
        actionCTAHuiCe = new QAction(QCTraderClass);
        actionCTAHuiCe->setObjectName(QString::fromUtf8("actionCTAHuiCe"));
        actiondatamanager = new QAction(QCTraderClass);
        actiondatamanager->setObjectName(QString::fromUtf8("actiondatamanager"));
        centralWidget = new QWidget(QCTraderClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 20, 901, 411));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 20, 871, 101));

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 20, 871, 101));

        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        tableView_3 = new QTableView(groupBox_3);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(10, 20, 871, 101));

        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        tableView_4 = new QTableView(groupBox_4);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setGeometry(QRect(10, 20, 871, 101));

        gridLayout_2->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        tableView_5 = new QTableView(groupBox_5);
        tableView_5->setObjectName(QString::fromUtf8("tableView_5"));
        tableView_5->setGeometry(QRect(10, 20, 871, 101));

        gridLayout_2->addWidget(groupBox_5, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        tableView_6 = new QTableView(groupBox_6);
        tableView_6->setObjectName(QString::fromUtf8("tableView_6"));
        tableView_6->setGeometry(QRect(10, 20, 871, 101));

        gridLayout_2->addWidget(groupBox_6, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        QCTraderClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QCTraderClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 951, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        QCTraderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QCTraderClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QCTraderClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QCTraderClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QCTraderClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(actionCTP);
        menu->addAction(actionQuit);
        menu_2->addAction(actionCTACeLue);
        menu_2->addAction(actionCTAHuiCe);
        menu_2->addAction(actiondatamanager);
        menu_4->addAction(actionabout);

        retranslateUi(QCTraderClass);
        QObject::connect(actionCTP, SIGNAL(triggered()), QCTraderClass, SLOT(menu_CTP_clicked()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QCTraderClass);
    } // setupUi

    void retranslateUi(QMainWindow *QCTraderClass)
    {
        QCTraderClass->setWindowTitle(QApplication::translate("QCTraderClass", "QCTrader", nullptr));
        actionCTP->setText(QApplication::translate("QCTraderClass", "CTP\350\277\236\346\216\245", nullptr));
        actionQuit->setText(QApplication::translate("QCTraderClass", "\351\200\200\345\207\272", nullptr));
        actionabout->setText(QApplication::translate("QCTraderClass", "\345\205\263\344\272\216", nullptr));
        actionCTACeLue->setText(QApplication::translate("QCTraderClass", "CTA\347\255\226\347\225\245", nullptr));
        actionCTAHuiCe->setText(QApplication::translate("QCTraderClass", "CTA\345\233\236\346\265\213", nullptr));
        actiondatamanager->setText(QApplication::translate("QCTraderClass", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        groupBox->setTitle(QApplication::translate("QCTraderClass", "\350\241\214\346\203\205", nullptr));
        groupBox_2->setTitle(QApplication::translate("QCTraderClass", "\345\247\224\346\211\230", nullptr));
        groupBox_3->setTitle(QApplication::translate("QCTraderClass", "\346\210\220\344\272\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QCTraderClass", "\350\241\214\346\203\205\345\222\214\344\272\244\346\230\223", nullptr));
        groupBox_4->setTitle(QApplication::translate("QCTraderClass", "\350\265\204\351\207\221", nullptr));
        groupBox_5->setTitle(QApplication::translate("QCTraderClass", "\346\214\201\344\273\223", nullptr));
        groupBox_6->setTitle(QApplication::translate("QCTraderClass", "\346\227\245\345\277\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QCTraderClass", "\350\264\246\346\210\267\345\222\214\346\227\245\345\277\227", nullptr));
        menu->setTitle(QApplication::translate("QCTraderClass", "\347\263\273\347\273\237", nullptr));
        menu_2->setTitle(QApplication::translate("QCTraderClass", "\345\212\237\350\203\275", nullptr));
        menu_3->setTitle(QApplication::translate("QCTraderClass", "\351\243\216\346\216\247", nullptr));
        menu_4->setTitle(QApplication::translate("QCTraderClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QCTraderClass: public Ui_QCTraderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCTRADER_H
