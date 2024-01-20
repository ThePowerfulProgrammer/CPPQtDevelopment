#include "workout.h"
#include <QDebug>

workout::workout()
{
    name = "";
    dateCreated = QDate::currentDate();
}

workout::workout(QString name, QDate date) : name(name), dateCreated(date)
{

}

void workout::addExercise(exercise ex)
{
    exercises.append(ex);
}

QString workout::getName()
{
    return name;
}

QDate workout::getDate()
{
    return dateCreated;
}


void workout::exerciseList()
{
    QList<exercise>::iterator i;
    for (i=exercises.begin();i != exercises.end();++i)
    {
        qDebug() << (*i).getName();
        qDebug() << '\n';
    }
}

QList<exercise> workout::getExercises()
{
    return exercises;
}

void workout::deleteWorkout()
{
    exercises.clear();
}

workout::~workout()
{
    //
}
