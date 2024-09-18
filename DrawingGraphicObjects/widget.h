#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "view.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsLineItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::Widget *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // WIDGET_H
