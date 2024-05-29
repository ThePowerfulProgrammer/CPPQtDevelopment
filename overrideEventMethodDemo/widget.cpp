#include "widget.h"
#include "ui_widget.h"
#include "button.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Button *btn = new Button(this);
    btn->setText("Btn");


//    connect(btn, &Button::clicked,[=](){ qDebug() << "This will not trigger" << "\n";}      ) ;
    ui->verticalLayout->addWidget(btn);
}

Widget::~Widget()
{
    delete ui;
}
