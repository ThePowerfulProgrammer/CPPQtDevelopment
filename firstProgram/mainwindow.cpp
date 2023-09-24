#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

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
    QString data = ui->lineEdit->text();
    QMessageBox::information(this,"Title", data);
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::question(this,"Question title", "Can you not read?");

}
