#include "widget.h"
#include "ui_widget.h"
#include "button.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    btn = new Button(this);
    btn->setText("User Btn");


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMouseEvent *mouseEvent = new QMouseEvent(QEvent::MouseButtonPress, QPointF(10,10), Qt::LeftButton,Qt::LeftButton, Qt::NoModifier);

    // we can SEND event
    if (QApplication::sendEvent(btn, mouseEvent))
    {
        qDebug() << "Event accepted \n \n \n";
    }
    else
    {
        qDebug() << "Event rejected \n";
    }


    // we can POST event
    QApplication::postEvent(btn,mouseEvent);

}
