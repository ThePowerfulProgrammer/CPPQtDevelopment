#include "exerciselist.h"
#include <QDebug>
QMap<int,exercise> exerciseList::listOfExercises; // all instances refer to the same QMap


exerciseList::exerciseList()
{
    // does nothing
    count = 0;
}

exerciseList::exerciseList(exercise* arrayOfExercises, int size)
{
    for (int i=0;i<size;i++)
    {
        listOfExercises.insert(arrayOfExercises[i].getId(),arrayOfExercises[i]); // Add instaces via array to our QMap
    }
}





QMap<int,exercise> exerciseList::getListOfExercises()
{
   return listOfExercises;
}

int exerciseList::getCount()
{
    return count;
}

void exerciseList::txtToExerciseList(QString fname)
{
    exerciseReader reader(fname); // open the reader
    while (!reader.endOfFile())
    {
        exercise ex(reader.readItem()); // create exercise
        listOfExercises.insert(ex.getId(),ex); // add exercise
    }
}

void exerciseList::exerciseListToTxt(QString fname)
{
    exerciseWriter writer(fname); // open the writer
    QMap<int,exercise>::const_iterator it;

    for (it = listOfExercises.constBegin();it != listOfExercises.constEnd();++it)
    {
        exercise ex = it.value();
        writer.writeItem(ex);
    }
}

void exerciseList::removeExercise(exercise *ex)
{
    listOfExercises.remove(ex->getId()); // Remove exercise using exercise.id
}

void exerciseList::append(exercise ex)
{
    listOfExercises[ex.getId()] = ex;
    count +=1;
}


void exerciseList::setCount(int c)
{
    count = c;
}
