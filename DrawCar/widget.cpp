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
    // create vars
    QPainterPath path;
    QPainter painter(this);
    painter.setPen(Qt::blue);

    // create tyres
    qDebug() << path.currentPosition() << "\n";
    path.moveTo(QPoint(150,250));
    path.addEllipse(path.currentPosition(),30,30);
    path.moveTo(150,250);
    qDebug() << path.currentPosition() << "\n";

    path.addEllipse(path.currentPosition(),50,50);
    qDebug() << path.currentPosition() << "\n";
    painter.drawPath(path);

    path.translate(400,0);
    painter.drawPath(path);

    // create front bonnet
    qDebug() << "Before front: "<< path.currentPosition() << "\n";
    path.moveTo(620,250);
    path.lineTo(700,250);
    path.lineTo(675,150);
    path.lineTo(525,150);
    painter.drawPath(path);
    qDebug() << path.currentPosition() << "\n";

    // create back boot
    path.moveTo(150,150);
    path.lineTo(80,150);
    path.lineTo(50,250);
    path.lineTo(80,250);
    painter.drawPath(path);
    qDebug() << path.currentPosition() << "\n";

    // complete the lower body
    QRectF rectangle(80,175,150,150);
    int startAngle = 0*16;
    int spanAngle = 180 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);

    path.moveTo(229,250);
    path.lineTo(470,250);
    painter.drawPath(path);

    qDebug() << rectangle.x() << "\n";
    qDebug() << rectangle.y() << "\n";
    rectangle.translate(390,0);
    painter.drawArc(rectangle, startAngle, spanAngle);

    // Connect to the back bonnet
    path.moveTo(525,150);
    path.lineTo(440,80);
    path.lineTo(200,80);
    path.lineTo(150,150);
    painter.drawPath(path);


    // draw the windows
    path.moveTo(180,150);

    painter.drawPath(path);
    rectangle.setWidth(150);
    rectangle.setHeight(150);
    startAngle = 90*16;
    spanAngle = 90 * 16;

    rectangle.translate(-290,-90);
    painter.drawPie(rectangle ,startAngle, spanAngle);

    qDebug() << rectangle.x() << "  Y: " << rectangle.y() << "\n";

    path.moveTo(275,160);
    path.lineTo(500,160);
    path.lineTo(420,85);
    path.lineTo(275, 85);
    path.lineTo(275, 160);
    painter.drawPath(path);

}











