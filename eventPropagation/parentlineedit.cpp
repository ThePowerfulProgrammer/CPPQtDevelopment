#include "parentlineedit.h"

ParentLineEdit::ParentLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}


void ParentLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "ParentLineEdit Key Pressed " << "\n";
    QLineEdit::keyPressEvent(event);
}
