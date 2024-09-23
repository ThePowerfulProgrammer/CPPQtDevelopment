#include "view.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>


View::View(QWidget *parent) :
    QGraphicsView(parent)
{
}


void View::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "View: coordinates " << event->pos() << "\n";
    QGraphicsView::mousePressEvent(event);
}

void View::keyPressEvent(QKeyEvent *event)
{
}
