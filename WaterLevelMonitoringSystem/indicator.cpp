#include "indicator.h"
#include <QPen>
#include <QBrush>
#include <QPainter>


Indicator::Indicator(QWidget *parent) :
    QWidget(parent),
    greenActive(false),
    redActive(false),
    yellowActive(false),
    lightsOn(true)
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));

    activateDanger();

    timer = new QTimer(this);
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

void Indicator::activateDanger()
{
    redActive = true;
    greenActive = yellowActive = false;
}

void Indicator::activateWarning()
{
    yellowActive = true;
    greenActive = redActive = false;
}

void Indicator::activateGo()
{
    greenActive = true;

    yellowActive = redActive = false;
}
