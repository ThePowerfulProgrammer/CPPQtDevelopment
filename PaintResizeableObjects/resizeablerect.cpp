#include "resizeablerect.h"
#include <QPen>
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>
#include "circleadjustitem.h"

ResizeableRect::ResizeableRect() : hasBeenDrawn(false)
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
}

void ResizeableRect::drawSizeControls()
{
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);


    if (isSelected())
    {

            // I need to draw a circle at the top left corner
            if (!hasBeenDrawn)
            {
                QPointF topLeftBoundedCorner = this->boundingRect().topLeft() + QPointF(-16.0,-16.0);
                QRectF rect = QRectF(topLeftBoundedCorner, QSize(17,17));

                ellipseTopLeft = new CircleAdjustItem(CircleAdjustItem::TopLeft,rect);
                ellipseTopLeft->setFlag(ItemIsMovable);
                ellipseTopLeft->setPen(pen);
                ellipseTopLeft->setBrush(QBrush(QColor(210, 1, 3, 50)));
                ellipseTopLeft->setParentItem(this);
                listOfAdjustableCircles.append(ellipseTopLeft);
                listOfAdjustableCircles[0]->setParentItem(this);

                this->scene()->addItem(ellipseTopLeft);

            }


            // I need a circle at the top right corner
            if (!hasBeenDrawn)
            {
                QPointF topRightBoundedCorner = this->boundingRect().topRight() + QPointF(0,-15.0);
                QRectF rectTopRight = QRectF(topRightBoundedCorner, QSize(17,17));

                ellipseTopRight = new CircleAdjustItem(CircleAdjustItem::TopRight, rectTopRight);
                ellipseTopRight->setFlag(QGraphicsItem::ItemIsMovable);
                ellipseTopRight->setPen(pen);
                ellipseTopRight->setBrush(QColor(4,27,255,50));
                ellipseTopRight->setParentItem(this);
                listOfAdjustableCircles.append(ellipseTopRight);
                listOfAdjustableCircles[1]->setParentItem(this);

                this->scene()->addItem(ellipseTopRight);

            }

            // I need a circle at the bottom left corner
            if (!hasBeenDrawn)
            {
                QPointF bottomLeftBoundedCorner = this->boundingRect().bottomLeft() + QPointF(-17.0,0);
                QRectF rectBottomLeft = QRectF(bottomLeftBoundedCorner, QSize(17,17));

                ellipseBotttomLeft = new CircleAdjustItem(CircleAdjustItem::BottomLeft, rectBottomLeft);
                ellipseBotttomLeft->setFlag(QGraphicsItem::ItemIsMovable);
                ellipseBotttomLeft->setPen(pen);
                ellipseBotttomLeft->setBrush(QColor(255,255,255,50));
                ellipseBotttomLeft->setParentItem(this);
                listOfAdjustableCircles.append(ellipseBotttomLeft);
                listOfAdjustableCircles[2]->setParentItem(this);

                this->scene()->addItem(ellipseBotttomLeft);

            }

            // I need a circle at the bottom right
            if (!hasBeenDrawn)
            {
                QPointF bottomRightBoundedCorner = this->boundingRect().bottomRight();
                QRectF rectBottomRight = QRectF(bottomRightBoundedCorner, QSize(17,17));

                ellipseBottomRight = new CircleAdjustItem(CircleAdjustItem::BottomLeft, rectBottomRight);
                ellipseBottomRight->setFlag(QGraphicsItem::ItemIsMovable);
                ellipseBottomRight->setPen(pen);
                ellipseBottomRight->setBrush(QColor(4,227,27,50));
                ellipseBottomRight->setParentItem(this);
                listOfAdjustableCircles.append(ellipseBottomRight);
                listOfAdjustableCircles[3]->setParentItem(this);

                this->scene()->addItem(ellipseBottomRight);
                qDebug() << "Run only once \n";
            }

            hasBeenDrawn = true;
    }
    else if (hasBeenDrawn && !isSelected())
    {
        foreach (CircleAdjustItem *circle, listOfAdjustableCircles)
        {
            scene()->removeItem(circle);
            qDebug() << "Delete circle " << "\n";
        }
        qDeleteAll(listOfAdjustableCircles);
        listOfAdjustableCircles.clear();
        hasBeenDrawn = false;
    }


}


void ResizeableRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->save();

    painter->setBrush(brush());

    painter->drawRect(rect());

    drawSizeControls();

    painter->restore();
}

void ResizeableRect::setFrame(QRectF newRect)
{
    prepareGeometryChange();
    setRect(newRect);
    update(); // calls paint
}
