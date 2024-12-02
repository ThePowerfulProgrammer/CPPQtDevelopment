#include "handleitem.h"
#include "resizeablerectitem.h"
#include <QGraphicsSceneMouseEvent>

HandleItem::HandleItem(Position pos) : handlePosition(pos)
{
    setFlag(QGraphicsItem::ItemIsMovable);
}


void HandleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    switch (handlePosition)
    {

    case TopLeft:
    {
        ResizeableRectItem *resizableRect = dynamic_cast<ResizeableRectItem*>(this->parentItem());
        if (resizableRect)
        {
            QRectF boundingFrameRect = resizableRect->selectorFrameBounds();
            boundingFrameRect.setTop(event->pos().y());
            boundingFrameRect.setLeft(event->pos().x());

            resizableRect->setSelectorFrameBounds(boundingFrameRect);

        }
    }


        break;

    case TopRight:
    {
        ResizeableRectItem *resizableRect = dynamic_cast<ResizeableRectItem*>(this->parentItem());
        if (resizableRect)
        {
            QRectF boundingFrameRect = resizableRect->selectorFrameBounds();
            boundingFrameRect.setTop(event->pos().y());
            boundingFrameRect.setRight(event->pos().x());

            resizableRect->setSelectorFrameBounds(boundingFrameRect);

        }
    }

        break;

    case BottomLeft:
    {
        ResizeableRectItem *resizableRect = dynamic_cast<ResizeableRectItem*>(this->parentItem());
        if (resizableRect)
        {
            QRectF boundingFrameRect = resizableRect->selectorFrameBounds();
            boundingFrameRect.setBottom(event->pos().y());
            boundingFrameRect.setLeft(event->pos().x());

            resizableRect->setSelectorFrameBounds(boundingFrameRect);

        }
    }

        break;


    case BottomRight:
    {
        ResizeableRectItem *resizableRect = dynamic_cast<ResizeableRectItem*>(this->parentItem());
        if (resizableRect)
        {
            QRectF boundingFrameRect = resizableRect->selectorFrameBounds();
            boundingFrameRect.setBottom(event->pos().y());
            boundingFrameRect.setRight(event->pos().x());

            resizableRect->setSelectorFrameBounds(boundingFrameRect);

        }
    }

        break;

    }

}
