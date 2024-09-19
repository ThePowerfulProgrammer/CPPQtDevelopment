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

    void drawLineTo(const QPoint &endPoint);



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
    bool areWeDrawing;
    QPoint currentPos;



    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event); // start my drawing
    void mouseReleaseEvent(QMouseEvent *event); // end my drawing
};

#endif // WIDGET_H
