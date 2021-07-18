/********************************************************************************
** Form generated from reading UI file 'ContractQueryManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRACTQUERYMANAGER_H
#define UI_CONTRACTQUERYMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContractQueryManager
{
public:

    void setupUi(QWidget *ContractQueryManager)
    {
        if (ContractQueryManager->objectName().isEmpty())
            ContractQueryManager->setObjectName(QString::fromUtf8("ContractQueryManager"));
        ContractQueryManager->resize(400, 300);

        retranslateUi(ContractQueryManager);

        QMetaObject::connectSlotsByName(ContractQueryManager);
    } // setupUi

    void retranslateUi(QWidget *ContractQueryManager)
    {
        ContractQueryManager->setWindowTitle(QApplication::translate("ContractQueryManager", "ContractQueryManager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContractQueryManager: public Ui_ContractQueryManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRACTQUERYMANAGER_H
