#include "widget.h"
#include "ui_widget.h"
#include "indicator.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Indicator *indicator = new Indicator(this);

}

Widget::~Widget()
{
    delete ui;
}
