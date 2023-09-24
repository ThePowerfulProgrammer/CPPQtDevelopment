#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "thirddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // opens 2nd window in a Modal(Superior) manner built on stack
    Dialog secDialog;
    secDialog.setModal(true);
    secDialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    // We can open 2nd window in a Modalless(Inferior) manner
    thDialog = new thirdDialog(this);
    thDialog->show();
}
