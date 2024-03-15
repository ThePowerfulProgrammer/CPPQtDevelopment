#include "mydialog.h"
#include <QDebug>
#include <QStandardItem>

myDialog::myDialog(QWidget *parent): QDialog(parent)
{
    model = new QStandardItemModel(4,4);
    for (int row = 0; row < model->rowCount(); ++row)
    {
        for (int column = 0; column < model->columnCount(); ++column)
        {
            QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
            model->setItem(row, column, item);
        }
    }

    tableView = new QTableView(this);

    tableView->setModel(model);

//    I want to create a singal and slot connection here that when I click a cell in my table, it streams the item to the console
    connect(tableView,SIGNAL(doubleClicked(QModelIndex)), this,SLOT(output());

    setWindowTitle("MVC");
    resize(400,400);
}


void myDialog::output()
{
    QStandardItem *item = tableView->indexAt(model->indexFromItem())
}

myDialog::~myDialog()
{
    delete model;
    delete tableView;
}
