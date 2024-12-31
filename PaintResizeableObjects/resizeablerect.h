#ifndef RESIZEABLERECT_H
#define RESIZEABLERECT_H


#include <QGraphicsRectItem>
#include <circleadjustitem.h>
#include <QGraphicsEllipseItem>
#include <QRectF>

class ResizeableRect : public QGraphicsRectItem
{
public:
    ResizeableRect();

    void drawSizeControls(); // draw 4 small circles at each vertex; will be called in paint
    void redrawSizeControls(); // if size change: Delete circles and redraw
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setFrame(QRectF newRect);


private:
    CircleAdjustItem *ellipseTopLeft;
    CircleAdjustItem *ellipseTopRight;
    CircleAdjustItem *ellipseBotttomLeft;
    CircleAdjustItem *ellipseBottomRight;
    QList<CircleAdjustItem*> listOfAdjustableCircles;

    bool hasBeenDrawn;
};

#endif // RESIZEABLERECT_H
