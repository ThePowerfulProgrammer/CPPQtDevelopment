#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resizeablerectitem.h"

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
    ResizeableRectItem *resizeableRect = new ResizeableRectItem;
    resizeableRect->setRect(100,100,50,50);
    resizeableRect->setBrush(QBrush(Qt::red));
    resizeableRect->setFlag(QGraphicsItem::ItemIsSelectable);


    scene->addItem(resizeableRect);

    view = new QGraphicsView; // the camera that allows the audience to view the performance

    view->setScene(scene);

    ui->verticalLayout->addWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}











