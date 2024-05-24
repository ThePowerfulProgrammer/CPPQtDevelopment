#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
