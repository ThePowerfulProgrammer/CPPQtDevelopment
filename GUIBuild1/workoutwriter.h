#ifndef WORKOUTWRITER_H
#define WORKOUTWRITER_H
#include <QString>
#include <QFile>
#include "workout.h"

class workoutWriter
{
public:
    workoutWriter(QString fname);

    void writeWorkout(Workout &w);

    ~workoutWriter();

private:
    QFile outputFile;
};



#endif // WORKOUTWRITER_H
