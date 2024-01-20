#ifndef EXERCISELIST_H
#define EXERCISELIST_H
#include "exercise.h"
#include "exercisereader.h"
#include "exercisewriter.h"
#include <QMap>

//Class to hold exercise objects
//Must be able to create a list from a text file
//Must be able to create a text file from a list
//Must search Exercise by name


class exerciseList
{
public:
    exerciseList();
    // default ctor

    exerciseList(exercise* arrayOfExercises, int size);

    void txtToExerciseList(QString fname);

    void exerciseListToTxt(QString fname);

    void append(exercise ex);

    void setCount(int c);

    QMap<int,exercise> getListOfExercises();

    int getCount();

    void removeExercise(exercise* ex);




private:
    int count; // Number of exercises
    static QMap<int,exercise> listOfExercises; // QMap sorts based on value of key, we will use exercise.id as key
};

#endif // EXERCISELIST_H
