#include "doubleclickablebutton.h"
#include <QDebug>

doubleClickableButton::doubleClickableButton(QWidget *parent) :
    QPushButton(parent)
{
}


void doubleClickableButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClicked();
    QPushButton::mouseDoubleClickEvent(event);
}



