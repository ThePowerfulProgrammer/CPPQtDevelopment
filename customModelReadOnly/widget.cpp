#include "widget.h"
#include "ui_widget.h"
#include "personmodel.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new PersonModel(this);

    ui->listView->setModel(model);
    ui->tableView->setModel(model);
    ui->treeView->setModel(model);

    ui->tableView->setSelectionModel(ui->listView->selectionModel());
    ui->treeView->setSelectionModel(ui->listView->selectionModel() );

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addData()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(removeData()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addData()
{
    Person *p = new Person("DogPack", "white", 23);
    model->addPerson(p);
}

void Widget::removeData()
{
    QModelIndex currentIndex = ui->listView->currentIndex();
    model->removePerson(currentIndex);
}
