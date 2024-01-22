#ifndef WORKOUT_H
#define WORKOUT_H
#include <QDate>
#include <QString>
#include <QList>
#include "exercise.h"

class Workout
{
public:
    Workout(); // base ctor sets defaults
    Workout(QString n); // 1 param ctor
    Workout(const Workout &wk); // copy ctor creates a deep copy

//    Workout txtToWorkout(QString fname, QString n); // create a workout object from a  text file

    QString getName(); // return name
    QDate getDate(); // return date
    QList<Exercise> getExercises(); // return QList<Exercise>

      void addExercise(Exercise ex); // add an Exercise object to vector

//    void writeToFile(QString fname); // write a Workout object to a file

//    void readFromFile(QString fname); // Read a file

private:
    QString name;
    QList<Exercise> exerciseList;


    QDate dateCreated;

};


#endif // WORKOUT_H
