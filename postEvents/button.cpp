#include "button.h"
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>


Button::Button(QWidget *parent) :
    QPushButton(parent)
{
}


void Button::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Button: Mouse Pressed \n";
    QPushButton::mousePressEvent(event);
}

void Button::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Button: Mouse Released \n";
    QPushButton::mouseReleaseEvent(event);
}

void Button::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Moused Moved at: "<< event->pos() << "\n";
    QPushButton::mouseMoveEvent(event);
}
