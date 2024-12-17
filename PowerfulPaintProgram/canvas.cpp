#include "canvas.h"
#include <QDebug>
#include <QPainter>
#include <QBrush>

Canvas::Canvas(QObject *parent) :
    QGraphicsScene(parent), firstPoint(), lastPoint(),isDrawing(false), penWidth(1)
{
    // setMinimumSize(QSize(720,880));
    addLine(360,0, 360, 880, QPen(QColor(0,0,0))); // y axis

    this->addLine(0,440,720,440,QPen(QBrush(QColor(0,0,0),Qt::SolidPattern), 1,Qt::SolidLine,
                                                   Qt::RoundCap, Qt::RoundJoin)); // x-axis

}

void Canvas::setPen()
{
    isDrawing = true;
}


void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->button() == Qt::LeftButton) && isDrawing)
    {
        // assign firstPos
        firstPoint = event->scenePos();

        qDebug() << "Clicked @: " << firstPoint << "\n";

    }

}


void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if ((event->buttons() && Qt::LeftButton) && isDrawing)
    {
        lastPoint = event->scenePos();

        this->addLine(QLineF(firstPoint, lastPoint), QPen(QBrush(QColor(0,0,0),Qt::SolidPattern), penWidth,Qt::SolidLine,
                                                         Qt::SquareCap, Qt::MiterJoin) );

        firstPoint = lastPoint;
        qDebug() << "Mouse @ " << event->scenePos() << "\n";

    }
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    firstPoint = event->scenePos();
    qDebug() << "End event \n";
}
int Canvas::getPenWidth() const
{
    return penWidth;
}

void Canvas::setPenWidth(int value)
{
    penWidth = value;
}

