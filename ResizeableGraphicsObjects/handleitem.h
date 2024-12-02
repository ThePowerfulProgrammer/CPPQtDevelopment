#ifndef HANDLEITEM_H
#define HANDLEITEM_H

#include <QGraphicsRectItem>

class HandleItem : public QGraphicsRectItem
{
public:
    // to indicate where the resize takes place
    enum Position
    {
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    HandleItem(Position pos);
    // QGraphicsItem interface
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


private:
    Position handlePosition;

};

#endif // HANDLEITEM_H
