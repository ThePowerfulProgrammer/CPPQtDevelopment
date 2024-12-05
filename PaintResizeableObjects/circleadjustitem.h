#ifndef CIRCLEADJUSTITEM_H
#define CIRCLEADJUSTITEM_H

#include <QGraphicsEllipseItem>


/**
Handles the apperance of the corners that move
Handles resizing the parent object

*/

class CircleAdjustItem : public QGraphicsEllipseItem
{
public:
    enum VertexPosition
    {
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    CircleAdjustItem(VertexPosition pos);
    CircleAdjustItem(VertexPosition pos,QRectF rect);



    // QGraphicsItem interface
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    VertexPosition position;
};

#endif // CIRCLEADJUSTITEM_H
