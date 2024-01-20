#include "exercisereader.h"
#include <QString>
#include <QFile>
#include <QStringList>

// still working on these lol I already forgot the params
exerciseReader::exerciseReader(QString fname) : inputFile(fname)
{
    //use inputFile variable to open a file, in read only mode and then interpret is as text
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
}


exercise exerciseReader::readItem()
{
    // PC: returns an instance of Exercise
    QStringList exerciseSL = QString(inputFile.readLine()).split('\t'); // For now maybe it works :)

    exercise ex(exerciseSL[0],exerciseSL[1],exerciseSL[2].toInt(),exerciseSL[3].toInt(),exerciseSL[4].toInt(),exerciseSL[5].toFloat(),exerciseSL[6].toFloat(),exerciseSL[7].toFloat());
    ex.setID(exerciseSL[8].toInt());
    return ex;
}

bool exerciseReader::endOfFile()
{
    return inputFile.atEnd();
}

exerciseReader::~exerciseReader()
{
    inputFile.close();
}

//Should be good


