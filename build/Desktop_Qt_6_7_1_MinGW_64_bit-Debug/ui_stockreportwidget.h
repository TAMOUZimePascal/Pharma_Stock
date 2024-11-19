/********************************************************************************
** Form generated from reading UI file 'stockreportwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKREPORTWIDGET_H
#define UI_STOCKREPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockReportWidget
{
public:

    void setupUi(QWidget *StockReportWidget)
    {
        if (StockReportWidget->objectName().isEmpty())
            StockReportWidget->setObjectName("StockReportWidget");
        StockReportWidget->resize(400, 300);

        retranslateUi(StockReportWidget);

        QMetaObject::connectSlotsByName(StockReportWidget);
    } // setupUi

    void retranslateUi(QWidget *StockReportWidget)
    {
        StockReportWidget->setWindowTitle(QCoreApplication::translate("StockReportWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StockReportWidget: public Ui_StockReportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKREPORTWIDGET_H
