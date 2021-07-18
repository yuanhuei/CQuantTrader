/********************************************************************************
** Form generated from reading UI file 'CTPConnectWidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTPCONNECTWIDGETS_H
#define UI_CTPCONNECTWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTPConnectWidgets
{
public:
    QPushButton *OkButton;
    QPushButton *CancelButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEdit_8;

    void setupUi(QDialog *CTPConnectWidgets)
    {
        if (CTPConnectWidgets->objectName().isEmpty())
            CTPConnectWidgets->setObjectName(QString::fromUtf8("CTPConnectWidgets"));
        CTPConnectWidgets->resize(423, 379);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CTPConnectWidgets->sizePolicy().hasHeightForWidth());
        CTPConnectWidgets->setSizePolicy(sizePolicy);
        CTPConnectWidgets->setMinimumSize(QSize(0, 0));
        CTPConnectWidgets->setMaximumSize(QSize(1000, 1000));
        OkButton = new QPushButton(CTPConnectWidgets);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setGeometry(QRect(60, 320, 141, 31));
        CancelButton = new QPushButton(CTPConnectWidgets);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setGeometry(QRect(250, 320, 121, 31));
        widget = new QWidget(CTPConnectWidgets);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 30, 271, 251));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setInputMethodHints(Qt::ImhPreferNumbers);

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_5->addWidget(lineEdit_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_6->addWidget(lineEdit_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_7->addWidget(lineEdit_7);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_8->addWidget(lineEdit_8);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(CTPConnectWidgets);
        QObject::connect(OkButton, SIGNAL(clicked()), CTPConnectWidgets, SLOT(buttonOk_clicked()));
        QObject::connect(CancelButton, SIGNAL(clicked()), CTPConnectWidgets, SLOT(buttonCancel_clicked()));

        QMetaObject::connectSlotsByName(CTPConnectWidgets);
    } // setupUi

    void retranslateUi(QDialog *CTPConnectWidgets)
    {
        CTPConnectWidgets->setWindowTitle(QApplication::translate("CTPConnectWidgets", "CTP\350\277\236\346\216\245", nullptr));
        OkButton->setText(QApplication::translate("CTPConnectWidgets", "\347\241\256\345\256\232", nullptr));
        CancelButton->setText(QApplication::translate("CTPConnectWidgets", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("CTPConnectWidgets", "\347\224\250\346\210\267\345\220\215\357\274\232    ", nullptr));
        lineEdit->setText(QApplication::translate("CTPConnectWidgets", "108758", nullptr));
        label_2->setText(QApplication::translate("CTPConnectWidgets", "\345\257\206\347\240\201\357\274\232      ", nullptr));
        lineEdit_2->setText(QApplication::translate("CTPConnectWidgets", "yh197687", nullptr));
        label_3->setText(QApplication::translate("CTPConnectWidgets", "\347\273\217\347\272\252\345\225\206\344\273\243\347\240\201\357\274\232", nullptr));
        lineEdit_3->setText(QApplication::translate("CTPConnectWidgets", "9999", nullptr));
        label_4->setText(QApplication::translate("CTPConnectWidgets", "\344\272\244\346\230\223\346\234\215\345\212\241\345\231\250\357\274\232", nullptr));
        lineEdit_4->setText(QApplication::translate("CTPConnectWidgets", "180.168.146.187:10201", nullptr));
        label_5->setText(QApplication::translate("CTPConnectWidgets", "\350\241\214\346\203\205\346\234\215\345\212\241\345\231\250\357\274\232", nullptr));
        lineEdit_5->setText(QApplication::translate("CTPConnectWidgets", "180.168.146.187:10211", nullptr));
        label_6->setText(QApplication::translate("CTPConnectWidgets", "\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232  ", nullptr));
        lineEdit_6->setText(QApplication::translate("CTPConnectWidgets", "simnow_client_test", nullptr));
        label_7->setText(QApplication::translate("CTPConnectWidgets", "\346\216\210\346\235\203\347\274\226\347\240\201\357\274\232  ", nullptr));
        lineEdit_7->setText(QApplication::translate("CTPConnectWidgets", "0000000000000000", nullptr));
        label_8->setText(QApplication::translate("CTPConnectWidgets", "\344\272\247\345\223\201\344\277\241\346\201\257\357\274\232  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTPConnectWidgets: public Ui_CTPConnectWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTPCONNECTWIDGETS_H
