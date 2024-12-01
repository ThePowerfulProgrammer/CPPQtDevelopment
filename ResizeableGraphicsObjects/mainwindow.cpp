#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentRect()
{
    ui->setupUi(this);


    rectItem = new QGraphicsRectItem(100,100,50,50);
    rectItem->setBrush(QBrush(QColor(255,27,4)));
    rectItem->setFlag(QGraphicsItem::ItemIsSelectable);
    rectItem->setFlag(QGraphicsItem::ItemIsMovable);




    scene = new QGraphicsScene; // the stage where we present the performance
    scene->addItem(rectItem);

    view = new QGraphicsView; // the camera that allows the audience to view the performance

    view->setScene(scene);

    ui->verticalLayout->addWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    currentRect = rectItem->rect();

    qDebug() << view->mapToScene(currentRect.topLeft().toPoint())  << " , " << view->mapToScene(currentRect.topRight().toPoint()) <<
                view->mapToScene(currentRect.bottomLeft().toPoint()) << view->mapToScene(currentRect.bottomRight().toPoint()) <<
                " Width: " << currentRect.width() << " Height: " << currentRect.height();

    currentRect.setBottomLeft(QPointF(currentRect.x() - 10, currentRect.y()));


}









