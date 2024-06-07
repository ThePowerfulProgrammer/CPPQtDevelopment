#include "indicator.h"
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QTimer>

Indicator::Indicator(QWidget *parent) :
    QWidget(parent),
    greenActive(true),
    redActive(false),
    yellowActive(false),
    lightsOn(true)
{

    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));

    QTimer *timer = new QTimer(this);
    timer->setInterval(300);
    connect(timer, SIGNAL(timeout()), this,SLOT(colorToggle()));
    timer->start();

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


    if (redActive)
    {
        painter.setBrush((lightsOn == true) ? Qt::red : Qt::black);
        painter.drawEllipse(10,10,100,100);

        painter.setBrush(Qt::black);
        painter.drawEllipse(10,118,100,100);

        painter.setBrush(Qt::black);
        painter.drawEllipse(10,225,100,100);
    }
    else if (greenActive)
    {
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,10,100,100);

        painter.setBrush((lightsOn == true) ? Qt::green : Qt::black);
        painter.drawEllipse(10,115,100,100);

        painter.setBrush(Qt::black);
        painter.drawEllipse(10,225,100,100);
    }
    else if (yellowActive)
    {
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,10,100,100);

        painter.setBrush(Qt::black);
        painter.drawEllipse(10,115,100,100);

        painter.setBrush((lightsOn == true) ? Qt::yellow : Qt::black);
        painter.drawEllipse(10,225,100,100);
    }


}

void Indicator::colorToggle()
{
    lightsOn = !lightsOn;
    update();
}
