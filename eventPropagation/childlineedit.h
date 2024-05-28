#ifndef CHILDLINEEDIT_H
#define CHILDLINEEDIT_H

#include "parentlineedit.h"
#include <QKeyEvent>

class ChildLineEdit : public ParentLineEdit
{
    Q_OBJECT
public:
    explicit ChildLineEdit(QWidget *parent = 0);

signals:

public slots:


protected:
    void keyPressEvent(QKeyEvent *event);

private:

};

#endif // CHILDLINEEDIT_H
