#include "widget.h"
#include "ui_widget.h"


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
    scene->addLine(-300,0,300,0, QPen(Qt::green)); // draw from (-300,0) - (300,0)
    scene->addLine(0,200,0,-200, QPen(Qt::blue)); // draw from (300,50) (300,-50)

}


Widget::~Widget()
{
    delete ui;
}

