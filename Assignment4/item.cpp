#include "item.h"

Item::Item(QString b, QString d, int s, double p) : barcode(b), description(d), stock(s), price(p)
{
    barcode.truncate(13);
    description.truncate(20);
}

bool Item::isValidBarcode(QString b)
{
    bool ok;
    int bInt = b.toInt(&ok);
    return ok && (bInt > 0);
}

QString Item::getBarcode() const
{
    return barcode;
}

QString Item::getDesription() const
{
    return description;
}

int Item::getStock() const
{
    return stock;
}

double Item::getPrice() const
{
    return price;
}

void Item::setStock(int s)
{
    stock = s;
}

QString Item::toString() const
{
    return QString("%1\t%2\t%3\t%4").arg(barcode,13).arg(description,20).arg(stock,5).arg(price,8,'f',2);
}

