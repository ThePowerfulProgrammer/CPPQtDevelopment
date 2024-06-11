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

    connect(tank, SIGNAL(emitNormal()),indicator, SLOT(activateGo()));
    connect(tank, SIGNAL(emitWarning()),indicator, SLOT(activateWarning()));
    connect(tank, SIGNAL(emitDanger()),indicator, SLOT(activateDanger()));

    ui->horizontalLayout->addWidget(tank);
    ui->horizontalLayout->addWidget(indicator);

}

Widget::~Widget()
{
    delete ui;
}
