#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QGraphicsLineItem>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    areWeDrawing(false)
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

    areWeDrawing = true;

}

// draw ellipise
void Widget::on_pushButton_2_clicked()
{

}

// draw path
void Widget::on_pushButton_3_clicked()
{

}


// draw image
void Widget::on_pushButton_6_clicked()
{

}


// draw pie
void Widget::on_pushButton_4_clicked()
{

}


// draw star
void Widget::on_pushButton_5_clicked()
{

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
    QGraphicsLineItem *Line = new QGraphicsLineItem;
    Line->setPen(QPen(Qt::black, 3));
    Line->setLine(currentPos.x(), currentPos.y(), endPoint.x(),endPoint.y());
    qDebug() << Line->pos() << "\n";

    currentPos = endPoint;
    scene->addItem(Line);
}



void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        currentPos = event->pos();
        areWeDrawing = true;

    }
}



void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && (areWeDrawing))
    {

        drawLineTo(event->pos());


    }
}
