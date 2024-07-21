#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "shapecanvas.h"


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
    void on_shapeCombo_activated(int index);

    void on_penWidthSpinBox_valueChanged(int arg1);

    void on_penStyleComboBox_activated(int index);

    void on_penCapComboBox_activated(int index);

    void on_penJoinComboBox_activated(int index);

    void on_brushStyleComboBox_activated(int index);

    void on_transformsCheckBox_toggled(bool checked);

    void on_antialisingCheckBox_toggled(bool checked);

    void penChanged();
    void brushChanged();



private:
    Ui::Widget *ui;
    ShapeCanvas *canvas;
};

#endif // WIDGET_H
