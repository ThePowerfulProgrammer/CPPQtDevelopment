#include "widget.h"
#include "ui_widget.h"
#include <QInputDialog>
#include <QMessageBox>
#include "persondelegate.h"

#include "stardelegate.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new PersonModel(this);
    PersonDelegate *delegate = new PersonDelegate(this);

    ui->listView->setModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(delegate);

    ui->treeView->setModel(model);
    ui->treeView->setItemDelegate(delegate);

    ui->tableView->setColumnWidth(2,150);
    ui->treeView->setColumnWidth(2,150);

    ui->tableView->setColumnWidth(3,150);
    ui->treeView->setColumnWidth(3,150);

    StarDelegate *starDelegate = new StarDelegate(this);
    ui->tableView->setItemDelegateForColumn(3,starDelegate);
    ui->treeView->setItemDelegateForColumn(3,starDelegate);

    ui->tableView->setSelectionModel(ui->listView->selectionModel());
    ui->treeView->setSelectionModel(ui->listView->selectionModel());

    setWindowTitle("Custom Table");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addPersonButton_clicked()
{
    bool ok;
       QString name = QInputDialog::getText(0, "Names",
                                            tr("Person name:"), QLineEdit::Normal,
                                            "Type in name", &ok);

       if (ok && !name.isEmpty()){

           int age = QInputDialog::getInt(0,"Person Age","Age",20,15,120);

            Person * person = new Person(name,"blue",age,5,this);

            model->addPerson(person);
       }else{
           QMessageBox::information(0,"Failure","Must specify name and age");
       }

}

void Widget::on_removePersonButton_clicked()
{
   QModelIndex index = ui->listView->currentIndex();
   model->removePerson(index);

}
