#include "shapecanvas.h"
#include <QPainter>

ShapeCanvas::ShapeCanvas(QWidget *parent) :
    QWidget(parent)
{
}

QSize ShapeCanvas::minimumSizeHint() const
{
    return QSize(400,200);
}

QSize ShapeCanvas::sizeHint() const
{
    return QSize(500,300);
}


void ShapeCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.drawRect(QRect(0,0,width() - 1, height() - 1));
}
bool ShapeCanvas::getTransformed() const
{
    return transformed;
}

void ShapeCanvas::setTransformed(bool value)
{
    transformed = value;
    update();
}

bool ShapeCanvas::getAntialiased() const
{
    return antialiased;
}

void ShapeCanvas::setAntialiased(bool value)
{
    antialiased = value;
    update();
}



QBrush ShapeCanvas::getBrush() const
{
    return brush;
}

void ShapeCanvas::setBrush(const QBrush &value)
{
    brush = value;
    update(); // calls the paint function
}

QPen ShapeCanvas::getPen() const
{
    return pen;
}

void ShapeCanvas::setPen(const QPen &value)
{
    pen = value;
    update(); // calls the paint function
}

ShapeCanvas::Shape ShapeCanvas::getShape() const
{
    return shape;
}

void ShapeCanvas::setShape(const Shape &value)
{
    shape = value;
    update(); // calls the paint function
}
