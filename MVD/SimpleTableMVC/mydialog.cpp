#include "mydialog.h"



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

    setWindowTitle("MVC");
    resize(400,400);
}

myDialog::~myDialog()
{
    delete model;
    delete tableView;
}
