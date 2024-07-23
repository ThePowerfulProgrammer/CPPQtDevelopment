#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"
#include <QPushButton>
#include <QCheckBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void toolRect();
    void toolEllipse();
    void toolPen();
    void toolEraser();

private slots:
    void penWidthChange(int width);
    void changePenColor();
    void changeFillColor();
    void changeFillProperty();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    QPushButton *penClrBtn;
    QPushButton *fillClrBtn;
    QCheckBox *fillCheckBox;
};



#endif // MAINWINDOW_H
