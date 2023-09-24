#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/new/rec/pics/open.png"),"Open");
    ui->comboBox->addItem(QIcon(":/new/rec/pics/close.png"),"Close");
    ui->comboBox->addItem(QIcon(":/new/rec/pics/new.jpg"),"New");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"Title",ui->comboBox->currentText());
}
