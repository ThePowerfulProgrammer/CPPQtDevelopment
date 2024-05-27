#include "childbutton.h"

ChildButton::ChildButton(QWidget *parent) : ParentButton(parent)
{

}


void ChildButton::mousePressEvent(QMouseEvent *event)
{
   qDebug() << "Child button mouse press event" << "\n";
   ParentButton::mousePressEvent(event);
}
