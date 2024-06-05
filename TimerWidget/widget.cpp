#include "widget.h"
#include "ui_widget.h"
#include "datetimewidget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    DateTimeWidget *widget = new DateTimeWidget(this);
    ui->verticalLayout_3->addWidget(widget);

}

Widget::~Widget()
{
    delete ui;
}
