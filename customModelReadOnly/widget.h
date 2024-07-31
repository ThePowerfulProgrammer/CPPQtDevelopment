#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "personmodel.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void addData();
    void removeData();
private:
    Ui::Widget *ui;
    PersonModel *model;
};

#endif // WIDGET_H
