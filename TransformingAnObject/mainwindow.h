#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Translate_X_valueChanged(int arg1);

    void on_Translate_Y_valueChanged(int arg1);

    void on_Degrees_of_Rotation_valueChanged(int arg1);

    void on_Scale_X_valueChanged(int arg1);

    void on_Scale_Y_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    int currentX = 0;

};

#endif // MAINWINDOW_H
