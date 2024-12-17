#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>

class Canvas : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Canvas(QObject *parent = 0);

signals:

public slots:

};

#endif // CANVAS_H
