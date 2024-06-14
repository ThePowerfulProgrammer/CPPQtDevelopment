#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>

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
    QPen pen(Qt::cyan);
    pen.setWidth(5);

    QPainter painter(this);
    painter.setPen(pen);

    qDebug() << "Logical Coordinates: " << painter.window() << "\n";
    qDebug() << "Physical coordinates " << painter.viewport() << "\n";
    painter.drawRect(50,50,100,50);

    // change the logical coordinates
    painter.save();

    painter.setWindow(0,0,300,200);
//    painter.setViewport(0,0,300,200); if same then no change

    pen.setColor(Qt::magenta);
    painter.setPen(pen);
    painter.drawRect(50,50,100,50);

    painter.restore();

    // change the physical coordinates
    painter.save();

    painter.setViewport(0,0,300,200);
    pen.setColor(Qt::green);

    painter.setPen(pen);
    painter.drawRect(50,50,100,50);

    painter.restore();

}
