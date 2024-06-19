#include "widget.h"
#include "ui_widget.h"
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
    QPainter painter(this);
    QPainterPath path;

    path.addRect(100,100,100,100);

    path.moveTo(150,150);

    path.lineTo(150,50);


    path.arcTo(50,50,200,200,90,90);

    qDebug() << path.currentPosition() << "\n";

    path.lineTo(150,150);

    qDebug() << path.currentPosition() << "\n";

    path.moveTo(150,250);
    path.lineTo(500,250);

    path.addEllipse(QPoint(150,300),50,50);

    qDebug() << path.currentPosition() << "\n";

    path.moveTo(150,350);
    path.lineTo(500,350);

    qDebug() << "MOST CUR: " << path.currentPosition() << "\n";

    path.addEllipse(QPoint(500,300), 50,50);

    painter.setBrush(Qt::cyan);
    painter.drawPath(path);
}









