#ifndef WORKOUT_H
#define WORKOUT_H
#include "exercise.h"
#include <QString>
#include <QList>
#include <QDate>

//The class A of our composition relationship composed of class B elements


class workout
{
public:
    workout();
    workout(QString name, QDate date);

    QList<exercise> getExercises();
    QString getName();
    QDate getDate();

    void addExercise(exercise ex);
    void exerciseList();

    void deleteWorkout();
    ~workout();
private:
    QString name;
    QDate dateCreated;
    QList<exercise> exercises;
};

#endif // WORKOUT_H
