#include "keyboardfilter.h"
#include <QKeyEvent>
#include <QDebug>

KeyboardFilter::KeyboardFilter(QObject *parent) :
    QObject(parent)
{
}


bool KeyboardFilter::eventFilter(QObject *watcher, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>( event );
        QString numbers = QString("1234567890");


        if (numbers.indexOf(keyEvent->text()) != -1)
        {
            qDebug() << "Number filted " << "\n";
            return true; // This is the event I want to handle
        }

    }
    return QObject::eventFilter(watcher, event);
}
