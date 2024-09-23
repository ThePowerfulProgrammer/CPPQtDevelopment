#include "widget.h"
#include "ui_widget.h"
#include "view.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    View *view = new View(this);

    ui->verticalLayout_3->addWidget(view);
}

Widget::~Widget()
{
    delete ui;
}
