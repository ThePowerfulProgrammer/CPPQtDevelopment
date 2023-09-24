#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "finddialog.h"
#include <QMainWindow>

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
    void showFindDialog(); // Optional slot to show the FindDialog

private:
    Ui::MainWindow *ui;
    findDialog* findDialog; // Private member variable for FindDialog
};

#endif // MAINWINDOW_H
