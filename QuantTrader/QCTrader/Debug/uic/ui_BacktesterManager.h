/********************************************************************************
** Form generated from reading UI file 'BacktesterManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKTESTERMANAGER_H
#define UI_BACKTESTERMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_BacktesterManager
{
public:
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QDateEdit *dateEdit_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QLineEdit *lineEdit_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLineEdit *lineEdit_14;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QFrame *frame_4;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_4;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QFrame *frame_6;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *widget;
    QCustomPlot *widget_2;
    QCustomPlot *widget_3;
    QCustomPlot *widget_4;

    void setupUi(QWidget *BacktesterManager)
    {
        if (BacktesterManager->objectName().isEmpty())
            BacktesterManager->setObjectName(QString::fromUtf8("BacktesterManager"));
        BacktesterManager->resize(951, 593);
        frame = new QFrame(BacktesterManager);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(9, 9, 491, 561));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(frame_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(frame_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        comboBox_2 = new QComboBox(frame_3);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_7->addWidget(comboBox_2);


        gridLayout_3->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        dateEdit = new QDateEdit(frame_3);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2010, 1, 4), QTime(0, 0, 0)));

        horizontalLayout_8->addWidget(dateEdit);


        gridLayout_3->addLayout(horizontalLayout_8, 3, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_11->addWidget(label_11);

        dateEdit_2 = new QDateEdit(frame_3);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setDateTime(QDateTime(QDate(2010, 1, 20), QTime(0, 0, 0)));

        horizontalLayout_11->addWidget(dateEdit_2);


        gridLayout_3->addLayout(horizontalLayout_11, 4, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        lineEdit_10 = new QLineEdit(frame_3);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        horizontalLayout_10->addWidget(lineEdit_10);


        gridLayout_3->addLayout(horizontalLayout_10, 5, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        lineEdit_9 = new QLineEdit(frame_3);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_9->addWidget(lineEdit_9);


        gridLayout_3->addLayout(horizontalLayout_9, 6, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_12->addWidget(label_12);

        lineEdit_12 = new QLineEdit(frame_3);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        horizontalLayout_12->addWidget(lineEdit_12);


        gridLayout_3->addLayout(horizontalLayout_12, 7, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_13->addWidget(label_13);

        lineEdit_13 = new QLineEdit(frame_3);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        horizontalLayout_13->addWidget(lineEdit_13);


        gridLayout_3->addLayout(horizontalLayout_13, 8, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_14 = new QLabel(frame_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_14->addWidget(label_14);

        lineEdit_14 = new QLineEdit(frame_3);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));

        horizontalLayout_14->addWidget(lineEdit_14);


        gridLayout_3->addLayout(horizontalLayout_14, 9, 0, 1, 1);

        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 10, 0, 1, 1);

        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 11, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        pushButton_4 = new QPushButton(frame_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_15->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_15->addWidget(pushButton_3);


        gridLayout_3->addLayout(horizontalLayout_15, 12, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        pushButton_5 = new QPushButton(frame_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_16->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(frame_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_16->addWidget(pushButton_6);


        gridLayout_3->addLayout(horizontalLayout_16, 13, 0, 1, 1);

        pushButton_7 = new QPushButton(frame_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout_3->addWidget(pushButton_7, 14, 0, 1, 1);

        pushButton_8 = new QPushButton(frame_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_3->addWidget(pushButton_8, 15, 0, 1, 1);


        horizontalLayout_4->addWidget(frame_3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        splitter_4 = new QSplitter(frame_4);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Vertical);
        frame_5 = new QFrame(splitter_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(frame_5);
        if (tableWidget->rowCount() < 25)
            tableWidget->setRowCount(25);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(24, __qtablewidgetitem24);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        splitter_4->addWidget(frame_5);
        frame_6 = new QFrame(splitter_4);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_6);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(frame_6);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        splitter_4->addWidget(frame_6);

        gridLayout_4->addWidget(splitter_4, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(frame_4);

        frame_2 = new QFrame(BacktesterManager);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(510, 10, 431, 511));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QCustomPlot(frame_2);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_2->addWidget(widget);

        widget_2 = new QCustomPlot(frame_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QCustomPlot(frame_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QCustomPlot(frame_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        verticalLayout_2->addWidget(widget_4);


        retranslateUi(BacktesterManager);
        QObject::connect(pushButton, SIGNAL(clicked()), BacktesterManager, SLOT(startBacktest_clicked()));

        QMetaObject::connectSlotsByName(BacktesterManager);
    } // setupUi

    void retranslateUi(QWidget *BacktesterManager)
    {
        BacktesterManager->setWindowTitle(QApplication::translate("BacktesterManager", "CTA\345\233\236\346\265\213", nullptr));
        label->setText(QApplication::translate("BacktesterManager", "\344\272\244\346\230\223\347\255\226\347\225\245", nullptr));
        label_2->setText(QApplication::translate("BacktesterManager", "\345\220\210\347\272\246\344\273\243\347\240\201", nullptr));
        lineEdit_2->setText(QApplication::translate("BacktesterManager", "al2109", nullptr));
        label_7->setText(QApplication::translate("BacktesterManager", "K\347\272\277\345\221\250\346\234\237", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("BacktesterManager", "\345\210\206\351\222\237", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("BacktesterManager", "\345\260\217\346\227\266", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("BacktesterManager", "\345\244\251", nullptr));

        label_8->setText(QApplication::translate("BacktesterManager", "\345\274\200\345\247\213\346\227\245\346\234\237", nullptr));
        label_11->setText(QApplication::translate("BacktesterManager", "\347\273\223\346\235\237\346\227\245\346\234\237", nullptr));
        label_10->setText(QApplication::translate("BacktesterManager", "\346\211\213\347\273\255\350\264\271\347\216\207", nullptr));
        lineEdit_10->setText(QApplication::translate("BacktesterManager", "2.5e-05", nullptr));
        label_9->setText(QApplication::translate("BacktesterManager", "\344\272\244\346\230\223\346\273\221\347\202\271", nullptr));
        lineEdit_9->setText(QApplication::translate("BacktesterManager", "0.5", nullptr));
        label_12->setText(QApplication::translate("BacktesterManager", "\345\220\210\347\272\246\344\271\230\346\225\260", nullptr));
        lineEdit_12->setText(QApplication::translate("BacktesterManager", "10", nullptr));
        label_13->setText(QApplication::translate("BacktesterManager", "\344\273\267\346\240\274\350\267\263\345\212\250", nullptr));
        lineEdit_13->setText(QApplication::translate("BacktesterManager", "0.5", nullptr));
        label_14->setText(QApplication::translate("BacktesterManager", "\345\233\236\346\265\213\350\265\204\351\207\221", nullptr));
        lineEdit_14->setText(QApplication::translate("BacktesterManager", "100000", nullptr));
        pushButton->setText(QApplication::translate("BacktesterManager", "\345\274\200\345\247\213\345\233\236\346\265\213", nullptr));
        pushButton_2->setText(QApplication::translate("BacktesterManager", "\344\270\213\350\275\275\346\225\260\346\215\256", nullptr));
        pushButton_4->setText(QApplication::translate("BacktesterManager", "\346\210\220\344\272\244\345\207\240\347\216\207", nullptr));
        pushButton_3->setText(QApplication::translate("BacktesterManager", "\345\247\224\346\211\230\350\256\260\345\275\225", nullptr));
        pushButton_5->setText(QApplication::translate("BacktesterManager", "\346\257\217\346\227\245\347\233\210\344\272\217", nullptr));
        pushButton_6->setText(QApplication::translate("BacktesterManager", "k\347\272\277\345\233\276\350\241\250", nullptr));
        pushButton_7->setText(QApplication::translate("BacktesterManager", "\345\217\202\346\225\260\344\274\230\345\214\226", nullptr));
        pushButton_8->setText(QApplication::translate("BacktesterManager", "\344\274\230\345\214\226\347\273\223\346\236\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BacktesterManager", "\351\246\226\344\270\252\344\272\244\346\230\223\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BacktesterManager", "\346\234\200\345\220\216\344\272\244\346\230\223\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BacktesterManager", "\346\200\273\344\272\244\346\230\223\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BacktesterManager", "\347\233\210\345\210\251\344\272\244\346\230\223\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BacktesterManager", "\344\272\217\346\215\237\344\272\244\346\230\223\346\227\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("BacktesterManager", "\350\265\267\345\247\213\350\265\204\351\207\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("BacktesterManager", "\347\273\223\346\235\237\350\265\204\351\207\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("BacktesterManager", "\346\200\273\346\224\266\347\233\212\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("BacktesterManager", "\345\271\264\345\214\226\346\224\266\347\233\212", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("BacktesterManager", "\346\234\200\345\244\247\345\233\236\346\222\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("BacktesterManager", "\347\231\276\345\210\206\346\257\224\346\234\200\345\244\247\345\233\236\346\222\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("BacktesterManager", "\346\200\273\347\233\210\344\272\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("BacktesterManager", "\346\200\273\346\211\213\347\273\255\350\264\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("BacktesterManager", "\346\200\273\346\273\221\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("BacktesterManager", "\346\200\273\346\210\220\344\272\244\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("BacktesterManager", "\346\200\273\346\210\220\344\272\244\347\254\224\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("BacktesterManager", "\346\227\245\345\235\207\347\233\210\344\272\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("BacktesterManager", "\346\227\245\345\235\207\346\211\213\347\273\255\350\264\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("BacktesterManager", "\346\227\245\345\235\207\346\273\221\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("BacktesterManager", "\346\227\245\345\235\207\346\210\220\344\272\244\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem20->setText(QApplication::translate("BacktesterManager", "\346\227\245\345\235\207\346\210\220\344\272\244\347\254\224\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem21->setText(QApplication::translate("BacktesterManager", "\346\227\245\345\235\207\346\224\266\347\233\212\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem22->setText(QApplication::translate("BacktesterManager", "\346\224\266\347\233\212\346\240\207\345\207\206\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem23->setText(QApplication::translate("BacktesterManager", "Sharpe Ratio", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(24);
        ___qtablewidgetitem24->setText(QApplication::translate("BacktesterManager", "\346\224\266\347\233\212\345\233\236\346\222\244\346\257\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BacktesterManager: public Ui_BacktesterManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKTESTERMANAGER_H
