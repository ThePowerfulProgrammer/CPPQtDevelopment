#ifndef RESIZEABLERECTITEM_H
#define RESIZEABLERECTITEM_H

#include <QGraphicsRectItem>
#include "handleitem.h"

class ResizeableRectItem : public QGraphicsRectItem
{
public:
    ResizeableRectItem();

    QRectF selectorFrameBounds() const;
    void setSelectorFrameBounds(QRectF boundsRect);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawHandlesIfNecessary();

private:
    void drawHandles(); // little corner squares
    QRectF topLeftHandleRect;
    QRectF topRightHandleRect;
    QRectF bottomRightHandleRect;
    QRectF bottomLeftHandleRect;

    QList<HandleItem*> handleList;
    bool handlesAddedToScene;


};

#endif // RESIZEABLERECTITEM_H
