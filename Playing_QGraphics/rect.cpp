#include "rect.h"
#include <QDebug>
#include <QKeyEvent>

Rect::Rect()
{
}


void Rect::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "BUtton pressed" << "\n";

    if (event->key() == Qt::Key_Left)
    {
        moveBy(-20,0);
    }
    else if (event->key() == Qt::Key_Right)
    {
        moveBy(20,0);
    }
    else if (event->key() == Qt::Key_Up)
    {
        moveBy(0, -20);
    }
    else if (event->key() == Qt::Key_Down)
    {
        moveBy(0,20);
    }

}
