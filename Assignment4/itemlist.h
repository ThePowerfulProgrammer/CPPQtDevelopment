#ifndef ITEMLIST_H
#define ITEMLIST_H
#include "itemlist.h"
#include "item.h"
#include "itemreader.h"
#include "itemwriter.h"
#include <QString>
#include <QMap> // dictionary in python {k:v}
#include <QFile>



class ItemList
{
public:
    ItemList();
    // base ctor

    ItemList(Item* arrayOfItems, int size);
//    Create a QMap of items sorted based on item price, read from an array containing items
//    PC: Create a Qmap of items

    void txtToItemList(QString fname);
    // uses itemreader to read in a txt file and create item instances that will be stored in the QMap

    void itemListToTxt(QString fname);
    // Traverse listOfItems
    // PC: write items from listOfItems to a txt file

    QMap<double,Item> getListOfItems();
    // PC: return listOfItems

    int getCount();
    // PC: return number of items in listOfItems

    Item* searchByBarcode(const QString& barcode);

    void removeItem(Item* item);



    static QMap<double,Item> listOfItems; /** Variable* */
    // QMap sorts based on value of key, price will be used as the key




private:
    int count; // number of items in listOfItems
};

#endif // ITEMLIST_H
