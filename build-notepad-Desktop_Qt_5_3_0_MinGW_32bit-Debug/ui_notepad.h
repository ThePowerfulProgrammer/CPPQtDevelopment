/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_notePad
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *quitButton;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *notePad)
    {
        if (notePad->objectName().isEmpty())
            notePad->setObjectName(QStringLiteral("notePad"));
        notePad->resize(430, 389);
        actionOpen = new QAction(notePad);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(notePad);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(notePad);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 30, 258, 229));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        verticalLayout->addWidget(quitButton);

        notePad->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(notePad);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 430, 26));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        notePad->setMenuBar(menuBar);
        mainToolBar = new QToolBar(notePad);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        notePad->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(notePad);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        notePad->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuOpen->addAction(actionOpen);
        menuOpen->addAction(actionSave);

        retranslateUi(notePad);

        QMetaObject::connectSlotsByName(notePad);
    } // setupUi

    void retranslateUi(QMainWindow *notePad)
    {
        notePad->setWindowTitle(QApplication::translate("notePad", "notePad", 0));
        actionOpen->setText(QApplication::translate("notePad", "Open", 0));
        actionSave->setText(QApplication::translate("notePad", "Save", 0));
        quitButton->setText(QApplication::translate("notePad", "Quit", 0));
        menuOpen->setTitle(QApplication::translate("notePad", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class notePad: public Ui_notePad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
