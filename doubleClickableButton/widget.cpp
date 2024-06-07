#include "widget.h"
#include "ui_widget.h"
#include "doubleclickablebutton.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    doubleClickableButton *btn = new doubleClickableButton(this);
    btn->setText("Click Me");

    connect(btn, SIGNAL(doubleClicked()), this, SLOT(printMessage()));

    ui->verticalLayout->addWidget(btn);
}

void Widget::printMessage()
{
    qDebug() << "I built this \n";
}


Widget::~Widget()
{
    delete ui;
}
