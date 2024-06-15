#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPoint>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPen pen;
    pen.setColor(Qt::darkMagenta);
    pen.setWidth(5);

    QPainter painter(this);

    painter.setPen(pen);
    painter.setBrush(Qt::green);
    painter.drawRect(10,10,150,100);

    painter.setBrush(Qt::darkRed);
    painter.drawEllipse(QPoint{300,200}, 150, 100);


    painter.setBrush(Qt::blue);
    painter.drawRoundRect(500,10, 150,100);

    pen.setColor(Qt::black);


}
