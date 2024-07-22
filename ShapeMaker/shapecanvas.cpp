#include "shapecanvas.h"
#include <QPainter>

ShapeCanvas::ShapeCanvas(QWidget *parent) :
    QWidget(parent)
{
    shape = Polygon;
    antialiased = false;
    transformed = false;
    pixmap.load(":/new/prefix1/images/marinK.jpeg");
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

    static const QPoint points[4] = {
        QPoint(10,80),
        QPoint(20, 10),
        QPoint(80,30),
        QPoint(90,70)
    };

    QRect rect(10,20,80,60);

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setFont( QFont("Oswald", 8, QFont::Bold));

    if (antialiased)
    {
        painter.setRenderHint(QPainter::Antialiasing, true);
    }

    for (int x = 0; x < width(); x+=100)
    {
        for (int y=0; y<height(); y+=100)
        {
            painter.save();

            painter.translate(x,y);

            if (transformed)
            {
                painter.translate(50,50);
                painter.rotate(60.0);
                painter.scale(0.6, 0.9);
                painter.translate(-50,-50);
            }

            switch (shape)
            {
                case Polygon:
                    painter.drawPolygon(points,4);
                    break;
                case Rect:
                    painter.drawRect(rect);
                    break;
                case RoundedRect:
                    painter.drawRoundedRect(rect, 25,25, Qt::RelativeSize);
                    break;
                case Ellipse:
                    painter.drawEllipse(rect);
                    break;
                case Chord:
                    painter.drawChord(rect, startAngle, arcLength);
                    break;
                case Pie:
                    painter.drawPie(rect, startAngle, arcLength);
                    break;
                case Text:
                    painter.drawText(rect,
                                     Qt::AlignCenter,
                                     tr("Qt Gui"));
                    break;
                case Pixmap:
                    painter.drawPixmap(10,10, pixmap);
                    break;
            }

            painter.restore();

        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setBrush(Qt::NoBrush);
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
