#include "itemwriter.h"
#include <QTextStream>

ItemWriter::ItemWriter(QString fname) : outputFile(fname)
{
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);
}

void ItemWriter::writeItem(const Item &i)
{
    QTextStream(&outputFile) << i.toString() << '\r' << '\n';
}

ItemWriter::~ItemWriter()
{
    outputFile.close();
}
