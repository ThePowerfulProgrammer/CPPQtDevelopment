#ifndef RECT_H
#define RECT_H

#include <QObject>
#include <QGraphicsRectItem>

class Rect : public QGraphicsRectItem
{

public:
    explicit Rect();

    // QGraphicsItem interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // RECT_H
