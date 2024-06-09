#include "widget.h"
#include "ui_widget.h"
#include "indicator.h"
#include "watertank.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Indicator *indicator = new Indicator(this);
    WaterTank *tank = new WaterTank(this);

    ui->horizontalLayout->addWidget(tank);
    ui->horizontalLayout->addWidget(indicator);

}

Widget::~Widget()
{
    delete ui;
}
