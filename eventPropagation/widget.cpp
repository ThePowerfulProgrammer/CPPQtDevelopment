#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ChildButton *button= new ChildButton(this);
    button->setText("Child Button");

    ChildLineEdit *lineEdit = new ChildLineEdit(this);
    lineEdit->setPlaceholderText("Type: ");



    ui->verticalLayout_2->addWidget(button);
    ui->verticalLayout_2->addSpacing(10);
    ui->verticalLayout_2->addWidget(lineEdit);


}

Widget::~Widget()
{
    delete ui;
}
