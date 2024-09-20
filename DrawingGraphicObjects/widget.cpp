#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QGraphicsLineItem>
#include <QMouseEvent>
#include <QGraphicsEllipseItem>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Vertical layout left
    scene = new QGraphicsScene(this);
    view = new View(this);



    view->setScene(scene);
    ui->verticalLayout_2->addWidget(view);

}



// draw line
void Widget::on_pushButton_clicked()
{
    QLineF line(QPointF(10,10), QPointF(90, 90));
    QGraphicsLineItem * lineItem = new QGraphicsLineItem(line);
    lineItem->setPen(QPen(Qt::red,3));

    QGraphicsRectItem * boundRectItem = new QGraphicsRectItem();
    boundRectItem->setRect(lineItem->boundingRect().adjusted(-10,-10,10,10));
    boundRectItem->setFlag(QGraphicsItem::ItemIsMovable);
    lineItem->setParentItem(boundRectItem);

    scene->addItem(boundRectItem);
}

// draw ellipise
void Widget::on_pushButton_2_clicked()
{
    QRectF rect(10,10,80,60);
    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(rect);
    ellipseItem->setBrush(QBrush(Qt::green));

    QGraphicsRectItem * boundRectItem = new QGraphicsRectItem();
    boundRectItem->setRect(ellipseItem->boundingRect().adjusted(-10,-10,10,10));
    boundRectItem->setFlag(QGraphicsItem::ItemIsMovable);
    ellipseItem->setParentItem(boundRectItem);

    scene->addItem(boundRectItem);
}

// draw path
void Widget::on_pushButton_3_clicked()
{
    QPainterPath path;
    path.addEllipse(QRectF(10,10,90,60));
    path.addRect(QRect(20,20,50,50));

    QGraphicsPathItem * painterPathItem = new QGraphicsPathItem(path);
    painterPathItem->setPen(QPen(Qt::black, 5));
    painterPathItem->setBrush(Qt::green);


    QGraphicsRectItem * boundRectItem = new QGraphicsRectItem();
    boundRectItem->setRect(painterPathItem->boundingRect().adjusted(-10,-10,10,10));
    boundRectItem->setFlag(QGraphicsItem::ItemIsMovable);
    painterPathItem->setParentItem(boundRectItem);

    scene->addItem(boundRectItem);
}


// draw image
void Widget::on_pushButton_6_clicked()
{

}


// draw pie
void Widget::on_pushButton_4_clicked()
{
    QPainterPath path(QPointF(60,60));
    path.arcTo(QRect(10,10,80,80), 30, 170);
    path.lineTo(QPointF(60,60));

    QGraphicsPathItem * piePath = new QGraphicsPathItem(path);
    piePath->setPen(QPen(Qt::black, 5));
    piePath->setBrush(Qt::green);


    QGraphicsRectItem * boundRectItem = new QGraphicsRectItem();
    boundRectItem->setRect(piePath->boundingRect().adjusted(-10,-10,10,10));
    boundRectItem->setFlag(QGraphicsItem::ItemIsMovable);
    piePath->setParentItem(boundRectItem);

}


// draw star
void Widget::on_pushButton_5_clicked()
{
    QPolygon poly;
    poly << QPoint(0, 85) << QPoint(75, 75)
         << QPoint(100, 10) << QPoint(125, 75)
         << QPoint(200, 85) << QPoint(150, 125)
         << QPoint(160, 190) << QPoint(100, 150)
         << QPoint(40, 190) << QPoint(50, 125)
         << QPoint(0, 85);

    QPainterPath path;
    path.addPolygon(poly);

    QGraphicsPathItem * starPath = new QGraphicsPathItem(path);
    starPath->setPen(QPen(Qt::black, 5));
    starPath->setBrush(Qt::green);


    QGraphicsRectItem * boundRectItem = new QGraphicsRectItem();
    boundRectItem->setRect(starPath->boundingRect().adjusted(-10,-10,10,10));
    boundRectItem->setFlag(QGraphicsItem::ItemIsMovable);
    starPath->setParentItem(boundRectItem);

    scene->addItem(boundRectItem);
}

// draw xy plane
void Widget::on_pushButton_13_clicked()
{

    scene->addLine(-350,0,350,0, QPen(Qt::green,3)); // draw from (-300,0) - (300,0)
    scene->addLine(0,250,0,-250, QPen(Qt::blue,3)); // draw from (300,50) (300,-50)

    qDebug() << "Drawn Now and drawn once \n";
    disconnect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(on_pushButton_13_clicked()));

}


Widget::~Widget()
{
    delete ui;
}

void Widget::drawLineTo(const QPoint &endPoint)
{
//    QGraphicsLineItem *Line = new QGraphicsLineItem;
//    Line->setPen(QPen(Qt::black, 3));
//    Line->setLine(currentPos.x(), currentPos.y(), endPoint.x(),endPoint.y());
//    QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(currentPos.x(), currentPos.y(),5,5);

//    scene->addItem(ellipse);
//    qDebug() << Line->pos() << "\n";

//    currentPos = endPoint;
//    scene->addItem(Line);

//    QGraphicsLineItem *l = new QGraphicsLineItem;
//    l->setLine(100,100,200,200);
//    scene->addItem(l);
}



void Widget::mousePressEvent(QMouseEvent *event)
{
//    if (event->buttons() == Qt::LeftButton)
//    {
//        currentPos = event->pos();
//        areWeDrawing = true;
//    }


}



void Widget::mouseReleaseEvent(QMouseEvent *event)
{
//    if (event->button() == Qt::LeftButton && (areWeDrawing))
//    {
//        qDebug() << "released \n";
//        drawLineTo(event->pos());
//    }

}
