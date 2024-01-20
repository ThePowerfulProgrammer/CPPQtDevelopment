#include "exercise.h"
#include <QDebug>
#include <QString>

int exercise::id = 0;
exercise::exercise() : name(""),description(""),RPE(0),sets(0),reps(0),max(0),workingWeight(0),rest(0)
{
    exercise::id++;
    unique_id = id;
}


// No need to explicitly call this->
exercise::exercise(QString name,QString description,int sets,int reps,int rpe,float workingWeight, float rest,float max)
{
    // take advantage of setters
    this->setName(name);
    this->setDescription(description);
    this->setMax(max);
    this->setWorkingWeight(workingWeight);
    this->setRest(rest);
    this->setRPE(rpe);
    this->setSets(sets);
    this->setReps(reps);
    exercise::id++;
    unique_id = id;
}

exercise::exercise(const exercise& other)
{
    name = other.name;
    description = other.description;
    max = other.max;
    workingWeight = other.workingWeight;
    rest = other.rest;
    RPE = other.RPE;
    sets = other.sets;
    reps = other.reps;
    id = other.id;
    unique_id = id;
}


 // setters :| silly me
void exercise::setName(QString s)
{
    name = s;
}

void exercise::setDescription(QString d)
{
    description = d;
    description.truncate(60); // is 60 chars enought? Yep
}

void exercise::setMax(float m)
{
    max = m;
}

void exercise::setWorkingWeight(float ww)
{
    // working weight can either be an absolute value or a % of max
    // will handle the functionality later
    workingWeight = ww;
}

void exercise::setRest(float r)
{
    rest = r;
}


void exercise::setRPE(int rpe)
{
    // level of perceived difficulty
    RPE = rpe;
}

void exercise::setSets(int s)
{
    sets = s;
}

void exercise::setReps(int r)
{
    reps = r;
}

void exercise::setID(int i)
{
    unique_id = i;
}

//I tended to make that mistake in my youth, guess old habits die hard


// Getters

QString exercise::getName()
{
    return name;
}

QString exercise::getDescription()
{
    return description;
}

float exercise::getMax()
{
    return max;
}

float exercise::getWorkingWeight()
{
    return workingWeight;
}

float exercise::getRest()
{
    return rest;
}

int exercise::getRPE()
{
    return RPE;
}

int exercise::getSets()
{
    return sets;
}

int exercise::getReps()
{
    return reps;
}

int exercise::getId()
{
    return unique_id;
}



// String repr: I hate spacing :) I have an idea what is happenning ok great

QString exercise::toString() const
{
    // BenchPress Description sets reps rpe ww rest max
    return QString("%1\t%2\t%3\t%4\t%5\t%6\t%7\t%8\t%9").arg(name, -10).arg(description, -20).arg(sets).arg(reps).arg(RPE).arg(workingWeight, 2).arg(rest, 3).arg(max, 3).arg(unique_id);
}





