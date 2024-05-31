#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "keyboardfilter.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->installEventFilter(new KeyboardFilter(this));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qDebug() << "We still have Signal Ourput here because we did not return true \n";
}
