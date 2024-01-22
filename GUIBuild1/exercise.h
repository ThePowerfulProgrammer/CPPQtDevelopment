#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>
#include <QString>
#include <QLabel>

using namespace std;

class Exercise
{
public:
    Exercise(); // base ctor sets default
    Exercise(QString n); // 1 param ctor
    Exercise(QString n, int s, int r, float ww); // 3 param ctor
    Exercise(const Exercise &ex); // copy ctor

    QString getName(); // return name
    int getSets(); // return sets
    int getReps(); // return reps
    float getWorkingWeight(); // return working Weight

    QString toString(); // return a str repr of the exercise

    void display(); // display the str repr of the exercise in a QLabel

    ~Exercise();

private:
    QString name;
    int sets;
    int reps;
    float workingWeight;
    QLabel *label; // holds toString()
};
#endif // EXERCISE_H
