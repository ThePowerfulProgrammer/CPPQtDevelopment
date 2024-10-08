#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // WIDGET_H
