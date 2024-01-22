#include "exercise.h"

Exercise::Exercise()
{
    name = "";
    sets = 0;
    reps = 0;
    workingWeight = 0.0;

    label = new QLabel();
    label->setGeometry(150,150,200,200);
}

Exercise::Exercise(QString n)
{
    name = n;
    sets = 0;
    reps = 0;
    workingWeight = 0;

    label = new QLabel();
    label->setGeometry(150,150,200,200);
}

Exercise::Exercise(QString n, int s, int r, float ww)
{
    name = n;
    sets = s;
    reps = r;
    workingWeight = ww;

    label = new QLabel();
    label->setGeometry(150,150,200,200);
}

Exercise::Exercise(const Exercise &ex)
{
    this->name = ex.name;
    this->sets = ex.sets;
    this->reps = ex.reps;
    this->workingWeight = ex.workingWeight;

    this->label = new QLabel();
    label->setGeometry(150,150,200,200);
}

QString Exercise::getName()
{
    return name;
}

int Exercise::getReps()
{
    return reps;
}

int Exercise::getSets()
{
    return sets;
}

float Exercise::getWorkingWeight()
{
    return workingWeight;
}

QString Exercise::toString()
{
    return QString("%1 %2x%3@%4").arg(name).arg(sets).arg(reps).arg(workingWeight,2,'f',2);
}


void Exercise::display() {
    label->setText(toString());
    label->show();
}

Exercise::~Exercise() {
    delete label;
}
