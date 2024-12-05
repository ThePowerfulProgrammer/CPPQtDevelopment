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
                QRectF boundingRectRectItem = rectItem->boundingRect(); // return current bounding rect
                boundingRectRectItem.setTop(event->pos().y());
                boundingRectRectItem.setLeft(event->pos().x());


                rectItem->setFrame(boundingRectRectItem);
            }
        }
        break;

        case TopRight:
        {
            ResizeableRect *rectItem = dynamic_cast<ResizeableRect*>(parentItem());
            if (rectItem)
            {
                QRectF boundingRectRectItem = rectItem->boundingRect(); // return current bounding rect
                boundingRectRectItem.setTopRight(event->pos());
                rectItem->setFrame(boundingRectRectItem);
            }
        }
        break;

    case BottomLeft:
        {
            ResizeableRect *rectItem = dynamic_cast<ResizeableRect*>(parentItem());
            if (rectItem)
            {
                QRectF boundingRectRectItem = rectItem->boundingRect(); // return current bounding rect
                boundingRectRectItem.setBottomLeft(event->pos());

                rectItem->setFrame(boundingRectRectItem);
            }

        }
        break;

    case BottomRight:
        {
            ResizeableRect *rectItem = dynamic_cast<ResizeableRect*>(parentItem());
            if (rectItem)
            {
                QRectF boundingRectRectItem = rectItem->boundingRect(); // return current bounding rect
                boundingRectRectItem.setBottomRight(event->pos());

                rectItem->setFrame(boundingRectRectItem);
            }

        }
        break;



    }

}
