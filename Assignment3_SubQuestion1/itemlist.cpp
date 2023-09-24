#include "itemlist.h"
#include <QDebug>

QMap<double, Item> itemList::listOfItems; // all instances refer to one list :)


itemList::itemList()
{

}

itemList::itemList(Item* arrayOfItems, int size): count(size)
{
    for (int i = 0;i<size;i++)
    {
        listOfItems.insert(arrayOfItems[i].getPrice(),arrayOfItems[i]);
    }
}

void itemList::txtToItemList(QString fname)
{
    ItemReader reader(fname);
    while (!reader.endOfFile())
    {
        Item item(reader.readItem());
        listOfItems.insert(item.getPrice(),item);
    }
}

void itemList::itemListToTxt(QString fname)
{
    ItemWriter writer(fname);
    QMap<double,Item>::const_iterator it;
    for (it = listOfItems.constBegin(); it != listOfItems.constEnd(); ++it)
    {
        // double key = it.key(); Do not need key
        Item item = it.value();
        // let's write
        writer.writeItem(item);
    }
}


QMap<double,Item> itemList::getListOfItems()
{
    return listOfItems;
}

int itemList::getCount()
{
    return count;
}

Item* itemList::searchByBarcode(const QString& barcode)
{
    QMap<double, Item>::iterator it;
    for (it = listOfItems.begin(); it != listOfItems.end(); ++it)
    {
        if (it.value().getBarcode() == barcode)
        {
            return (&it.value());
        }
    }
    return 0; // Barcode not found. OH NO :|
}

void itemList::removeItem(Item* item)
{
    listOfItems.remove(item->getPrice()); // bye bye
}
