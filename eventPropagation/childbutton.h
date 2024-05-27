#ifndef CHILDBUTTON_H
#define CHILDBUTTON_H
#include "parentbutton.h"

#include <QPushButton>
#include <QDebug>

class ChildButton : public ParentButton
{
    Q_OBJECT
public:
    explicit ChildButton(QWidget *parent = 0);

signals:

public slots:

protected:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // CHILDBUTTON_H
