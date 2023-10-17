#ifndef ITEMWRITER_H
#define ITEMWRITER_H

#include "item.h"
#include <QString>
#include <QFile>


class ItemWriter
{
public:
    ItemWriter(QString fname);
    void writeItem(const Item& i);
    ~ItemWriter();
private:
    QFile outputFile;
};

#endif // ITEMWRITER_H
