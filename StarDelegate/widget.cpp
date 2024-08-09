#include "widget.h"
#include "ui_widget.h"
#include "stardelegate.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // First entry
    temp.append(QVariant("Beginning Qt C++ GUI Development"));
    temp.append(QVariant("Qt C++ GUI"));
    temp.append(QVariant(3));
    data.append(temp);

    // Clear temp for next entry
    temp.clear();

    // Second entry
    temp.append(QVariant("Qt Quick and QML For Beginners"));
    temp.append(QVariant("QML"));
    temp.append(QVariant(5));
    data.append(temp);

    // Clear temp for next entry
    temp.clear();

    // Third entry
    temp.append(QVariant("Qt Quick and QML Intermediate"));
    temp.append(QVariant("QML"));
    temp.append(QVariant(4));
    data.append(temp);

    // Clear temp for next entry
    temp.clear();

    // Fourth entry
    temp.append(QVariant("Qt Quick and QML Advanced"));
    temp.append(QVariant("QML"));
    temp.append(QVariant(4));
    data.append(temp);

    // Clear temp for next entry
    temp.clear();

    // Fifth entry
    temp.append(QVariant("Qt 5 C++ GUI Intermediate"));
    temp.append(QVariant("Qt C++ GUI"));
    temp.append(QVariant(1));
    data.append(temp);

    // Clear temp for next entry
    temp.clear();

    // Sixth entry
    temp.append(QVariant("Qt 5 C++ GUI Advanced"));
    temp.append(QVariant("Qt C++ GUI"));
    temp.append(QVariant(5));
    data.append(temp);


    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(data[0].size());
    ui->tableWidget->setColumnWidth(0,300);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,300);


    for (int row = 0; row < data.size() ; row++)
    {
        QTableWidgetItem *item0 = new QTableWidgetItem(data[row][0].toString());
        QTableWidgetItem *item1 = new QTableWidgetItem(data[row][1].toString());
        QTableWidgetItem *item2 = new QTableWidgetItem(data[row][2].toString());

        ui->tableWidget->setItem(row,0,item0);
        ui->tableWidget->setItem(row,1,item1);
        ui->tableWidget->setItem(row,2,item2);
    }

    StarDelegate *delegate = new StarDelegate(this);
    ui->tableWidget->setItemDelegateForColumn(2,delegate);

}

Widget::~Widget()
{
    delete ui;
}
