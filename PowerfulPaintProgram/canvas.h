#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Canvas : public QGraphicsScene
{

public:
    explicit Canvas(QObject *parent = 0);

    enum Tool
    {
        Pen,
    };

    void setPen();



    // QGraphicsScene interface
    int getPenWidth() const;
    void setPenWidth(int value);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:

    QPointF firstPoint;
    QPointF lastPoint;
    bool isDrawing;
    int penWidth;


};

#endif // CANVAS_H
