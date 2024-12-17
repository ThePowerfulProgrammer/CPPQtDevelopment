#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QToolBar>
#include <QPushButton>
#include <QIcon>
#include <QSpinBox>
#include "canvas.h"

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);

signals:

public slots:
    void setToolPen();
    void setToolPenWidth();

private:
    Canvas *canvas;
    QToolBar *toolBar;

    QPushButton *btnOne;
    QSpinBox *penWidthSpinBox;
};

#endif // DIALOG_H
