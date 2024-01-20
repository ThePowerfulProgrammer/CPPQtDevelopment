#ifndef EXERCISEREADER_H
#define EXERCISEREADER_H
#include "exercise.h"
#include <QString>
#include <QFile>

class exerciseReader
{
public:
    //exerciseReader(); NO need for a default ctor

    exerciseReader(QString fname);

    exercise readItem();
    // PC: returns an Instance of exercise

    bool endOfFile();
    // PC: returns true if end of file, else false

    ~exerciseReader();
private:
    QFile inputFile;

};

#endif // EXERCISEREADER_H
