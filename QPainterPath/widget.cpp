#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("QPath drawing");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::cyan);
    QPainterPath path;

    path.addRect(100,100,100,100);

    path.moveTo(150,150);

    path.lineTo(150,50);


    path.arcTo(50,50,200,200,90,90);

    path.lineTo(150,150);


    path.lineTo(150,150);


    path.moveTo(150,250);
    path.lineTo(500,250);

    path.addEllipse(QPoint(150,300),50,50);


    path.moveTo(150,350);
    path.lineTo(500,350);

    path.moveTo(300,450);
    path.addEllipse(QPoint(300,450),50,50);


    path.moveTo(300,400);
    path.lineTo(650,400);
    path.addEllipse(QPoint(650,450),50,50);

    path.moveTo(300,500);
    path.lineTo(650,500);

    path.addEllipse(QPoint(500,300), 50,50);


    painter.drawPath(path);
}









