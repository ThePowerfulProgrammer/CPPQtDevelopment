#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Item
{
public:
    Item(QString b, QString d, int s, double p);
//    b refers to an Item barcode
//    d refers to an Item description
//    s refers to an Item stock
//    p refers to an Item price
//    PC: Create an instance of Item class where all values are set.

    static bool isValidBarcode(QString b);
    // PC: return true if valid, else false

    QString getBarcode() const;
    // PC: return barcode

    QString getDesription() const;
    // PC: return description

    double getPrice() const;
    // PC: return Price

    int getStock() const;
    // PC: return stock

    void setStock(int s);
    // PC: set the stock to s

    QString toString() const;
//     PC: returns a QString repr of our class instance


private:
    QString barcode;
    QString description;
    int stock;
    double price;


};

#endif // ITEM_H
