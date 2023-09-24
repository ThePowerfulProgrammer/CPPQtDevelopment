#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

#include <QTimer>
#include <QLabel>
#include "dialog.h"

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
    QString text = ui->lineEdit->text();
    bool conversionOK = false;
    int timeChange = text.toInt(&conversionOK);

    if (conversionOK) {
        // Conversion was successful, and timeChange contains the time interval

        // Create an instance of dialog, and rotate through the 3 images
        Dialog dialog(0, timeChange);
        dialog.setModal(true);
        dialog.exec();

    } else {
        // Conversion failed, handle the error
        Dialog dialog(0, 5000); // we pass a default of 5000ms = 5 seconds
        dialog.setModal(true); // prevent accessing other windows until dialog is closed
        dialog.exec();
    }
}

