#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    findDialog = new FindDialog(this); // Create an instance of FindDialog
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFindDialog()
{
    findDialog->show(); // Show the FindDialog
    // You can also perform additional operations with the FindDialog here.
}
