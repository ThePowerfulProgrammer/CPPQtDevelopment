#include "watertank.h"
#include <QPen>
#include <QPainter>

WaterTank::WaterTank(QWidget *parent) :
    QWidget(parent), waterLevel(50), timer(new QTimer(this))
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
}


QSize WaterTank::sizeHint() const
{
    return QSize(400,400);
}

void WaterTank::paintEvent(QPaintEvent *event)
{
    // set up pen
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::darkMagenta);

    QPainter painter(this);
    painter.setPen(pen);

    painter.setBrush(Qt::darkMagenta);
    painter.drawLine(0,0,0,315); // Left horizontal line
    painter.drawLine(0,315,315,315); // bottom line
    painter.drawLine(315,315,315,0); // right line

    painter.setBrush(Qt::blue);
    painter.drawRect(QRect(0,315-waterLevel,315,waterLevel));


}
