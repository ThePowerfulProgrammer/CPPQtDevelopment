#include "itemlist.h"

QMap<double,Item> ItemList::listOfItems; // all instances refer to one list :)

ItemList::ItemList()
{
    // does nothing
}

ItemList::ItemList(Item *arrayOfItems, int size)
{
    for (int i=0;i<size;i++)
    {
        listOfItems.insert(arrayOfItems[i].getPrice(),arrayOfItems[i]); // add instance to our QMap
    }
}

void ItemList::txtToItemList(QString fname)
{
    ItemReader reader(fname);
    while (!reader.endOfFile())
    {
        Item item(reader.readItem());
        listOfItems.insert(item.getPrice(),item);
    }
}

void ItemList::itemListToTxt(QString fname)
{
    ItemWriter writer(fname);
    QMap<double,Item>::const_iterator it;

    for (it = listOfItems.constBegin(); it!=listOfItems.constEnd(); ++it)
    {
        Item item = it.value();

        writer.writeItem(item);
    }
}


QMap<double,Item> ItemList::getListOfItems()
{
    return listOfItems;
}

int ItemList::getCount()
{
    return count; // incredibly difficult function
}

Item* ItemList::searchByBarcode(const QString &barcode)
{
    QMap<double,Item>::iterator it;
    for (it = listOfItems.begin(); it != listOfItems.end(); ++it)
    {
        if (it.value().getBarcode() == barcode) // successful match
        {
            return (&it.value());
        }
    }
    return 0; // Barcode not found, you fool. OH NO :|
}

void ItemList::removeItem(Item *item)
{
    listOfItems.remove(item->getPrice()); // bye bye item
}




















