#include "parentbutton.h"

ParentButton::ParentButton(QWidget *parent) :
    QPushButton(parent)
{
}


void ParentButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Parent Button mouse press event" << "\n";
    QPushButton::mousePressEvent(event);
}
