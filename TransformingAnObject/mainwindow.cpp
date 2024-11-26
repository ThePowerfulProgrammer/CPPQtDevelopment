#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Translate_X->setMinimum(-100);
    ui->Translate_X->setMaximum(100);
    ui->Degrees_of_Rotation->setMaximum(360);

    scene.addLine(250,0,250,500, QPen(Qt::blue));
    scene.addLine(0,250, 500,250);


   QGraphicsRectItem *greenRect = scene.addRect(253,262,200,100);
   greenRect->setPen(Qt::NoPen);
   greenRect->setFlag(QGraphicsItem::ItemIsMovable);
   greenRect->setBrush(QBrush(Qt::green));


    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Translate_X_valueChanged(int arg1)
{
    QList<QGraphicsItem*> items = ui->graphicsView->items();
    QTransform transform;
    transform.translate(arg1,0);

    items[0]->setTransform(transform);

}

void MainWindow::on_Translate_Y_valueChanged(int arg1)
{
    QList<QGraphicsItem*> items = ui->graphicsView->items();
    items[0]->setY(items[0]->y() + arg1);
}




void MainWindow::on_Degrees_of_Rotation_valueChanged(int arg1)
{
    QList<QGraphicsItem*> items = ui->graphicsView->items();
    QTransform transform;
    transform.rotate(arg1,Qt::YAxis);
    items[0]->setTransform(transform);

}

void MainWindow::on_Scale_X_valueChanged(int arg1)
{
    QList<QGraphicsItem*> items = ui->graphicsView->items();
    QTransform transform;
    transform.scale(arg1,1);
    items[0]->setTransform(transform);
}

void MainWindow::on_Scale_Y_valueChanged(int arg1)
{
    QList<QGraphicsItem*> items = ui->graphicsView->items();
    QTransform transform;
    transform.scale(1,arg1);
    items[0]->setTransform(transform);
}
