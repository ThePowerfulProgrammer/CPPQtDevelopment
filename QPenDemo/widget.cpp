#include "widget.h"
#include "ui_widget.h"
#include <QVector>

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
    // default drawing
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::green);

    QPainter painter(this);
    painter.setPen(pen);
    painter.drawRect(10,10,100,100);


    // drawing and brush fill
    painter.setBrush(Qt::magenta);
    painter.drawRect(120,10, 100,100);


    // changing pen style
    pen.setStyle(Qt::DashLine);
    pen.setColor(Qt::darkRed);
    painter.setPen(pen);
    painter.drawRect(230,10,100,100);

    //
    pen.setStyle(Qt::DashDotDotLine);
    pen.setColor(Qt::darkRed);
    painter.setPen(pen);
    painter.drawRect(350,10,100,100);

    // user defined dashes
    pen.setColor(Qt::red);
    painter.setBrush(Qt::black);
    QVector<qreal> dashes;
    qreal space = 4;
    dashes << 1 << space << 3 << space << 9 << space << 27 << space << 9 << space;
    pen.setDashPattern(dashes);
    painter.setPen(pen);
    painter.drawRect(10,130, 100,100);

    // change pen cap style
    QPoint start(120,300);
    QPoint end(500,300);
    pen.setWidth(20);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);
    painter.drawLine(start,end);

    // another pen style && how to move QPoint
    start.setY(400);
    end.setY(400);
    pen.setWidth(20);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.drawLine(start,end);

    // middle pen style
    QPoint startMid(120,340);
    QPoint endMid(500,340);
    pen.setWidth(20);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::SquareCap);
    painter.setPen(pen);
    painter.drawLine(startMid,endMid);


    // Joining and drawing lines
    QPointF points[4] = {
        QPointF(660.0, 380.0),
        QPointF(610.0, 310.0),
        QPointF(870.0, 330.0),
        QPointF(800.0, 370.0)
    };

    pen.setColor(Qt::blue);
    pen.setWidth(15);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);

    painter.drawPolygon(points,4);

    // lets change the join style

    for (int i=0; i<4; i++)
    {
        points[i].setY(points[i].y()+100.0);
    }
    pen.setColor(Qt::green);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);
    painter.drawPolygon(points,4);

}









