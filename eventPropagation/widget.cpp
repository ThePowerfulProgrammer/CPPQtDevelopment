#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ChildButton *button= new ChildButton(this);
    button->setText("Child Button");



    ui->verticalLayout_2->addWidget(button);


}

Widget::~Widget()
{
    delete ui;
}
