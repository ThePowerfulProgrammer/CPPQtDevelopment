#include "button.h"
#include <QEvent>
#include <QDebug>

Button::Button(QWidget *parent) :
    QPushButton(parent)
{
}


bool Button::event(QEvent *event)
{

    if (event->type() ==  QEvent::MouseButtonDblClick || event->type() == QEvent::MouseButtonPress  )
    {
        qDebug() << "Mouse click or double click event received" << "\n";
        return true;
    }
    QPushButton::event(event);


}
