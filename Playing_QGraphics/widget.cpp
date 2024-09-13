#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>
#include "rect.h"
#include "view.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this); // Consider this a model from a MVD

//    QGraphicsRectItem *rect = new QGraphicsRectItem(10,10,100,50);
//    rect->setFlag(QGraphicsItem::ItemIsMovable);
//    QPen pen;
//    pen.setWidth(3);
//    pen.setColor(Qt::green);
//    rect->setPen(pen);
//    scene->addItem(rect);
//    scene->addRect(110,50,200,200);

    scene->addLine(-300,0,300,0);
    scene->addLine(0,-300,0,300);

    Rect *myrect = new Rect();
    myrect->setRect(400,100,100,200);
    myrect->setFlag(QGraphicsItem::ItemIsFocusable);
    myrect->setFocus();
    myrect->setPen(QPen(Qt::red));
    scene->addItem(myrect);



//    QGraphicsView *view = new QGraphicsView(this); // regular view
    View *view = new View(this);
    view->setScene(scene);
    ui->verticalLayout_4->addWidget(view);
    setWindowTitle("Playing with GVF");
}

Widget::~Widget()
{
    delete ui;
}
