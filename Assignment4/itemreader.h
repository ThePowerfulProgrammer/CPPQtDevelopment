#ifndef ITEMREADER_H
#define ITEMREADER_H

#include "item.h"
#include <QString>
#include <QFile>

class ItemReader
{
public:
    ItemReader(QString fname);
    // PC: Reads a txt file and processes contents into Item instances

    Item readItem();
    // PC: returns an Instance of Item

    bool endOfFile();
    // PC: returns true if end of file, else false

    ~ItemReader();
private:
    QFile inputFile;
};

#endif // ITEMREADER_H
