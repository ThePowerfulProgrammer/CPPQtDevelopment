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

    Workout readWorkout();

    bool endOfFile();

private:
    QFile inputFile;
};


#endif // WORKOUTREADER_H
