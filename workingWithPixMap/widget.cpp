#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pMap(this->width() - 20, this->height() - 20);

    QPen pen;
    pen.setWidth(8);
    pen.setColor(Qt::white);

    QPainter painter(&pMap);
    painter.setPen(pen);
    painter.setBrush(Qt::cyan);

    painter.drawRect(50,50,200,100);

    ui->label->setPixmap(pMap);

}

Widget::~Widget()
{
    delete ui;
}
