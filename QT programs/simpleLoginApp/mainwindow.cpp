#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 1st way to set pics
    QPixmap pix(":/resource/img/berserk.jpg");
    int w = ui->label_pic->width();
    int h = ui->label->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    // 2nd method -> use pixmap in ui file, under a filter for label
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_password->text();
    if (username == "test" && password == "test")
    {
         QMessageBox::information(this, "Login", "Username and password is correct");
         hide();
         dialog = new Dialog(this);
         dialog->show();
    }
    else
    {
        QMessageBox::warning(this, "Login","Username and password is incorrect");
    }

}
