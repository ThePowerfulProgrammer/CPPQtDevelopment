#ifndef EXERCISE_H
#define EXERCISE_H
#include <QString>

//Used as part of a composite relationship
//Consider it class B, which composes class A

class exercise
{
public:
    exercise(); // default ctor
    exercise(QString name,int sets, int reps,int workingWeight); // parameter ctor

    QString getName();
    int getSets();
    int getReps();
    float getWorkingWeight();

    QString toString(); // members to string format


private:
    QString name;
    int sets;
    int reps;
    float workingWeight;
};

#endif // EXERCISE_H
