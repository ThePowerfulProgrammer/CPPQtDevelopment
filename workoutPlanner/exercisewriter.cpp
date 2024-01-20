#include "exercisewriter.h"
#include <QTextStream>

exerciseWriter::exerciseWriter(QString fname) : outputFile(fname)
{
    outputFile.open(QIODevice::Append | QIODevice::Text);
    //Unlike reading, we are not only writing to a file but also allowing appending to a txt file
}

void exerciseWriter::writeItem(const exercise &ex)
{
    QTextStream(&outputFile) << ex.toString() << '\r' <<  '\n';
}


exerciseWriter::~exerciseWriter()
{
    // BUTTTTTTT we have no pointers, why do we need a destructor?
    outputFile.close();
}
