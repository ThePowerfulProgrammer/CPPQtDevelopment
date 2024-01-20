#ifndef EXERCISEWRITER_H
#define EXERCISEWRITER_H
#include "exercise.h"
#include <QString>
#include <QFile>


class exerciseWriter
{
public:
    // exerciseWriter(); just for the gags for now ;)
    exerciseWriter(QString fname);

    void writeItem(const exercise & ex);
    // PC: returns an Instance of exercise


    ~exerciseWriter();
    // dtor
private:
    QFile outputFile;
};

#endif // EXERCISEWRITER_H
