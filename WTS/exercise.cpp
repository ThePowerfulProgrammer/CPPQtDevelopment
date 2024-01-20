#include "exercise.h"

exercise::exercise()
{
    name = "";
    sets = 0;
    reps = 0;
}

exercise::exercise(QString name,int sets, int reps,int workingWeight)
{
    name = name;
    sets = sets;
    reps = reps;
    workingWeight = workingWeight;
}

QString exercise::getName()
{
    return name;
}

int exercise::getSets()
{
    return sets;
}

int exercise::getReps()
{
    return reps;
}

float exercise::getWorkingWeight()
{
    return workingWeight;
}

QString exercise::toString()
{
    return QString("%1\t%2\t%3\t%4").arg(name,30).arg(sets,3).arg(reps,3).arg(workingWeight,3,'f',2);
}



