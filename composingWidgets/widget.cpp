#include "widget.h"
#include "ui_widget.h"
#include "colorpicker.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ColorPicker * cp = new ColorPicker(this);
    connect(cp, SIGNAL(colorChanged(QColor)), this, SLOT(colorChanged(QColor)));

    ui->verticalLayout->addWidget(cp);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::colorChanged(QColor color)
{
    qDebug() << "Color changed to : " << color.name() << "\n";
}
