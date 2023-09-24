#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->pushButton_2->setText("about");
    ui->pushButton_3->setText("aboutQt");
    ui->pushButton_4->setText("CritiKal");\
    ui->pushButton_5->setText("question");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    // create various types of message box (parent, title, text), where parent is (this)
    // void     about
    // void     aboutQt
    // StandardButton   critical
    // StandardButton   information
    // StandardButton   question
    // StandardButton   warning
    QMessageBox::about(this, "Message box title", "This is a message Box object");
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::aboutQt(this, "Title");
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::critical(this, "This is critical", "System failure!");
}



void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "A question", "Are you a machine?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    } else
    {
        qDebug() << "NO was clicked"; // will display in console

    }

}
