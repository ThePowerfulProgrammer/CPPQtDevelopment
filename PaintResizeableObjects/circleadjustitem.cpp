#include "circleadjustitem.h"
#include <QGraphicsSceneMouseEvent>
#include "resizeablerect.h"
#include <QGraphicsScene>
#include <QDebug>

CircleAdjustItem::CircleAdjustItem(VertexPosition pos): position(pos)
{
    setFlag(QGraphicsEllipseItem::ItemIsMovable);
}

CircleAdjustItem::CircleAdjustItem(VertexPosition pos,QRectF rect) : QGraphicsEllipseItem(rect),position(pos)
{
    setFlag(QGraphicsEllipseItem::ItemIsMovable);
}




void CircleAdjustItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

   // how to handle resizing a rect's boundingRect

    switch (position)
    {
        case TopLeft:
        {
            ResizeableRect *rectItem = dynamic_cast<ResizeableRect*>(parentItem());
            if (rectItem)
            {
                QRectF boundingRectRectItem = rectItem->rect() ; // return current bounding rect
                boundingRectRectItem.setTop(event->pos().y() + 6);
                boundingRectRectItem.setLeft(event->pos().x()  - 6);


                rectItem->setFrame(boundingRectRectItem.normalized());

            }
        }
        break;

        case TopRight:
        {
            ResizeableRect *rectItem = dynamic_cast<ResizeableRect*>(parentItem());
            if (rectItem)
            {
                QRectF boundingRectRectItem = rectItem->rect(); // return current bounding rect
                boundingRectRectItem.setTopRight(event->pos() + QPointF(6, -6));
                rectItem->setFrame(boundingRectRectItem.normalized());
            }
        }
        break;

    case BottomLeft:
        {
            ResizeableRect *rectItem = dynamic_cast<ResizeableRect*>(parentItem());
            if (rectItem)
            {
                QRectF boundingRectRectItem = rectItem->rect(); // return current bounding rect
                boundingRectRectItem.setBottomLeft(event->pos() + QPointF(-6,6));

                rectItem->setFrame(boundingRectRectItem.normalized());


            }

        }
        break;

    case BottomRight:
        {
            ResizeableRect *rectItem = dynamic_cast<ResizeableRect*>(parentItem());
            if (rectItem)
            {
                QRectF boundingRectRectItem = rectItem->rect(); // return current bounding rect

                boundingRectRectItem.setBottomRight(event->pos() + QPointF(-6,-6)) ;


                rectItem->setFrame(boundingRectRectItem.normalized());
                qDebug() << "Top Left: " << boundingRectRectItem.topLeft() << "\n";
            }

        }
        break;



    }

}
