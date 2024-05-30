#include "filter.h"
#include <QEvent>
#include <QDebug>

Filter::Filter(QObject *parent) :
    QObject(parent)
{
}


bool Filter::eventFilter(QObject *watched, QEvent *event)
{

    if (event->type() == QEvent::MouseButtonPress
            || event->type() == QEvent::MouseButtonDblClick)
    {
        qDebug() << "Mouse Press Event has been hijacked in filter \n";
        qDebug() << "Read Docs, but if I return True... \n\n\n\n\n";
        qDebug() << "---------------------------------------------- \n";
    }

    return QObject::eventFilter(watched, event);
}
