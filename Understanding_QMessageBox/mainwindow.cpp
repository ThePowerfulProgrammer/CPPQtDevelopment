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
    QString title = "About 'About'";
    QMessageBox::about(this,title, "About information");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::aboutQt(this,"About 'aboutQt'");
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::critical(this,"Big Oops :O", "You done f'ed Up!");
}



void MainWindow::on_pushButton_4_clicked()
{
   QMessageBox::StandardButton reply =  QMessageBox::question(this, "A title?", "Do you understand?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QMessageBox::information(this,"Yes Title","Congrats you are'nt dumb");
    }
    else
    {
        QMessageBox::information(this,"No Title", "Clearly you're dumb");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this,"This is info", "Provides some context");
}

void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox::warning(this,"System fail...", "You have been warned");
}
