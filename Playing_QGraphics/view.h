#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);

signals:

public slots:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // VIEW_H
