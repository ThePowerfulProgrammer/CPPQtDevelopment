#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include "dialog.h"
#include "sortdialog.h"
#include "finddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPixmap pix(":/pics/pics/Dragon.jpg");
    ui->setupUi(this);
    ui->label_pic->setPixmap(pix.scaled(ui->label_pic->height(),ui->label_pic->width(),Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "Ash" && password == "Ramnath")
    {

        QMessageBox::information(this,"LOGGED IN","Succesfully logged In.");
        Dialog dialog;
        dialog.setModal(true);
        dialog.exec();
        ui->statusBar->clearMessage();
        findDialog *fDialog = new findDialog;
        fDialog->show();
    } else
    {
        QMessageBox::warning(this,"Not Logged In", "Unsuccesful log in.");
        ui->statusBar->showMessage("FAILURE",1000);
        sortDialog *dialog = new sortDialog;
        dialog->setColumnRange('A','H');
        dialog->show();

    }
}


void MainWindow::on_pushButton_Login_pressed()
{
    // OOPS
}
