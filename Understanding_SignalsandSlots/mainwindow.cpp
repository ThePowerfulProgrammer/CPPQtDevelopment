#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Another way to create a signal & slot relationship
    // horizontalSlider emits the SIGNAL, it will invoke the SLOT() function in progressBar

    //connect(ui->horizontalSlider, SIGNAL(valueChanged(int), ui->progressBar, SLOT(setValue(int));
    //disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int), ui->progressBar, SLOT(setValue(int));

}

MainWindow::~MainWindow()
{
    delete ui;
}
