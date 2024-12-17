#ifndef DRAGENABLEDVIEW_H
#define DRAGENABLEDVIEW_H

#include <QGraphicsView>
#include <QDrag>
#include <QMimeData>

class QDragEnterEvent;
class QDragMoveEvent;
class QDragLeaveEvent;
class QDropEvent;

class DragEnabledView : public QGraphicsView
{

public:
    explicit DragEnabledView(QWidget *parent = 0);

signals:

public slots:


    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // DRAGENABLEDVIEW_H
