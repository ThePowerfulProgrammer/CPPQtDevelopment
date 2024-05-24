#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "MOuse Pressed @: " << event->pos() << "\n";
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "MOuse Released@: " << event->pos() << "\n";
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "MOuse Moved@: " << event->pos() << "\n";
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "Widget about to close" << "\n";
    event->accept();
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "Contect Menu Event activated upon right mouse click: " << "\n";
}
