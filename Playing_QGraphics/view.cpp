#include "view.h"
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsRectItem>

View::View(QWidget *parent) :
    QGraphicsView(parent)
{

}


void View::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Coordinate in scene " << event->pos();

    QPointF point = mapToScene(event->pos());

    qDebug() << "Coordinate in view " << point.x() << " " << point.y();


    QGraphicsRectItem *rect = scene()->addRect(point.x(),point.y(), 20,20);
    QGraphicsRectItem *viewrect = scene()->addRect(event->pos().x(),event->pos().y(), 20,20);
    rect->setBrush(QBrush(Qt::green));
    viewrect->setBrush(QBrush(Qt::blue));
}
