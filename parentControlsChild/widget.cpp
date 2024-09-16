#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGraphicsView *view = new QGraphicsView(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsRectItem *rect = new QGraphicsRectItem(400,400,100,100);
    rect->setBrush(Qt::red);
    rect->setFlag(QGraphicsItem::ItemIsMovable);

    QGraphicsRectItem *rectChild = new QGraphicsRectItem(450,475,50,50);
    rectChild->setBrush(Qt::green);
    rectChild->setParentItem(rect);

    scene->addItem(rect);

    view->setScene(scene);

    ui->verticalLayout_3->addWidget(view);
}

Widget::~Widget()
{
    delete ui;
}
