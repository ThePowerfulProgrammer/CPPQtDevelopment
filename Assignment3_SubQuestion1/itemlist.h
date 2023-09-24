#ifndef ITEMLIST_H
#define ITEMLIST_H
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\item.h"
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\itemwriter.h"
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\itemreader.h"
#include <QString>
#include <QMap>
#include <QFile>

class itemList
{
public:
    itemList();
    // base ctor

    itemList(Item* arrayOfItems, int size);
    // Create a QMap of items sorted based on item price, read from an array containing items
    // PC: Create a QMap of items sorted based on item price && sets count to size

    void txtToItemList(QString fname);
    // Use file to read till the end of a file, creating Item object instances
    // PC: Add instances to listOfItems

    void itemListToTxt(QString fname);
    // Traverse listOfItems
    // PC: write items from listOfItems to a txt file

    QMap<double,Item> getListOfItems();
    // PC: returns listOfItems

    int getCount();
    // PC: returns count

    static QMap<double,Item> listOfItems; // QMap sorts based on value of key, we will use item.price as key

    Item* searchByBarcode(const QString& barcode);

    void removeItem(Item* item);

private:

    int count; // number of item in listOfItems
};


#endif // ITEMLIST_H
