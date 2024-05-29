#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = 0);

signals:

public slots:


    // QObject interface
public:
    bool event(QEvent *event);
};

#endif // BUTTON_H
