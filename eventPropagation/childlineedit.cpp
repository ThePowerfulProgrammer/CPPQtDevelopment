#include "childlineedit.h"

ChildLineEdit::ChildLineEdit(QWidget *parent) :
    ParentLineEdit(parent)
{
}


void ChildLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "ChildLineEdit key pressed" << "\n";

    qDebug() << event->isAccepted() << "\n";

    if (event->key() == Qt::Key_Delete)
    {
         qDebug() << "Delete key has been pressed" << "\n";
        this->clear();
    }
    else
    {
        ParentLineEdit::keyPressEvent(event);
    }
}
