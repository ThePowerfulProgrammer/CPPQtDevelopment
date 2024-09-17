#include "widget.h"
#include "ui_widget.h"
#include "view.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsLineItem>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Vertical layout left
    QGraphicsScene *scene = new QGraphicsScene(this);
    View *view = new View(this);

    scene->addLine(-300,0,300,0);


    view->setScene(scene);
    ui->verticalLayout_2->addWidget(view);


    // vertical layout right
    QPushButton *lineBtn = new QPushButton("Line", this);
    QPushButton *rectBtn = new QPushButton("Rectangle", this);
    QPushButton *ellipseBtn = new QPushButton("Ellipse", this);
    ui->verticalLayout_3->addWidget(lineBtn);
    ui->verticalLayout_3->addWidget(rectBtn);
    ui->verticalLayout_3->addWidget(ellipseBtn);


}

Widget::~Widget()
{
    delete ui;
}
