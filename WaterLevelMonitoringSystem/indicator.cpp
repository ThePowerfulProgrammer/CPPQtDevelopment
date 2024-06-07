#include "indicator.h"
#include <QPen>
#include <QBrush>
#include <QPainter>

Indicator::Indicator(QWidget *parent) :
    QWidget(parent),
    redActive(false),
    yellowActive(false),
    greenActive(false)
{

    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}


QSize Indicator::sizeHint() const
{
    return QSize(120,350);
}


// First time widget is destroyed
void Indicator::paintEvent(QPaintEvent *event)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);

    QPainter painter(this);
    painter.setPen(pen);

    painter.setBrush(Qt::darkCyan);
    painter.drawRect(QRect(0,0,120,330));

    painter.setBrush(Qt::red);
    painter.drawEllipse(10,10,100,100);

    painter.setBrush(Qt::yellow);
    painter.drawEllipse(10,115,100,100);

    painter.setBrush(Qt::darkGreen);
    painter.drawEllipse(10,225,100,100);

}
