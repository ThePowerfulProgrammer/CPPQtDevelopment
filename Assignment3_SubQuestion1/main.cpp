#include <QCoreApplication>
#include <QApplication>
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\item.h"
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\itemreader.h"
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\itemwriter.h"
#include "itemlist.h"
#include "itemlist.h"
#include "itemdialog.h"
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    /* Sub Question 1
    Item i1("1122334455667", "Solar panels", 1, 16500.0);
    Item i2("0101234567899", "Asus tuf i5", 3, 16800.0);
    Item i3("0134234567899", "Mouse", 2, 145.50);
    Item i4("1111234567899", "PS5", 4, 19000.0);

    ItemReader reader("C:/Users/ashis/OneDrive/Desktop/Item_reader_writer/Item_reader_writer/infile.txt");
    ItemWriter writer("outfile.txt");

    while (!reader.endOfFile())
    {
        Item item(reader.readItem());
        writer.writeItem(item);
    }


    Item items[4] = {i1,i2,i3,i4};
    itemList myItemList(items,4);

    myItemList.txtToItemList("C:/Users/ashis/OneDrive/Desktop/Item_reader_writer/Item_reader_writer/infile.txt");
    myItemList.itemListToTxt("output.txt");
    */

    // Test question 2

//    QApplication a(argc, argv);

//    Item* item = ItemDialog::addItem();

//    if(item != 0)
//    {
//        // Process the new item
//        qDebug() << item->getBarcode() << " " << item->getDescription() << " " << item->getStock() << " " << item->getPrice() << "\n";
//    }

//    Item* newItem = ItemDialog::changeItem(item);
//    if(item != 0)
//    {
//        // Process the changed item
//        qDebug() << newItem->getBarcode() << " " << newItem->getDescription() << " " << newItem->getStock() << " " << newItem->getPrice() << "\n";
//    }


    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
