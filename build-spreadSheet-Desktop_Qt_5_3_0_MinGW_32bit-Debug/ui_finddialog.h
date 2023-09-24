/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_finddialog
{
public:

    void setupUi(QDialog *finddialog)
    {
        if (finddialog->objectName().isEmpty())
            finddialog->setObjectName(QStringLiteral("finddialog"));
        finddialog->resize(400, 300);

        retranslateUi(finddialog);

        QMetaObject::connectSlotsByName(finddialog);
    } // setupUi

    void retranslateUi(QDialog *finddialog)
    {
        finddialog->setWindowTitle(QApplication::translate("finddialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class finddialog: public Ui_finddialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
