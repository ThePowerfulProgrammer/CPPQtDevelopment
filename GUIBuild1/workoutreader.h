#ifndef WORKOUTREADER_H
#define WORKOUTREADER_H
#include "workout.h"
#include <QString>
#include <QFile>

class workoutReader
{
public:
    workoutReader(QString fname);
    ~workoutReader();

    Workout readWorkout(QString name);

    bool endOfFile();

private:
    QFile inputFile;
};


#endif // WORKOUTREADER_H
