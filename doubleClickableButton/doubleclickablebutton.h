#ifndef DOUBLECLICKABLEBUTTON_H
#define DOUBLECLICKABLEBUTTON_H

#include <QPushButton>

class doubleClickableButton : public QPushButton
{
    Q_OBJECT
public:
    explicit doubleClickableButton(QWidget *parent = 0);

signals:
    void doubleClicked();

public slots:


    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // DOUBLECLICKABLEBUTTON_H
