#include <QCoreApplication>
#include <QApplication>
#include "item.h"
#include "itemreader.h"
#include "itemwriter.h"
#include "itemlist.h"
#include "itemdialog.h"
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);

//    Item *item = ItemDialog::addItem();

//    if (item != 0)
//    {
//        qDebug() << item->getBarcode() << " " << item->getDesription() << " " << item->getStock() << " " << item->getPrice();
//    }
//    return a.exec();

      QApplication app(argc,argv);
      mainWindow mainWindow;
      mainWindow.show();
      return app.exec();

}
