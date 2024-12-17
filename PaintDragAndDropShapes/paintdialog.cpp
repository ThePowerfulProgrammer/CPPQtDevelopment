#include "paintdialog.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include <QDebug>

#include "dragenabledview.h"


PaintDialog::PaintDialog(QWidget *parent) :
    QDialog(parent)
{

    shapeList = new ShapeList(this);

    QHBoxLayout *layoutOne = new QHBoxLayout;
    layoutOne->addWidget(shapeList);


    QHBoxLayout *layoutTwo = new QHBoxLayout;
    QGraphicsRectItem *rect =  new QGraphicsRectItem(295,215,50,50);
    rect->setBrush(QBrush(QColor(225,27,4)));
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    QGraphicsScene *scene = new QGraphicsScene;

//    Parent X:  640

//    Parent Y:  480

    scene->addLine(320,0,320,480, QPen(QColor(Qt::red)));
    scene->addLine(0,240,640,240, QPen(QColor(Qt::cyan)));

    scene->addItem(rect);


    DragEnabledView *view = new DragEnabledView;
    view->setScene(scene);

    layoutTwo->addWidget(view);


    QHBoxLayout *mainLayout =  new QHBoxLayout;
    mainLayout->addLayout(layoutOne);
    mainLayout->addSpacing(25);
    mainLayout->addLayout(layoutTwo);


    setMinimumSize(1000,500);
    setAcceptDrops(true);
    setLayout(mainLayout);
    setWindowFlags(Qt::Window);


}



