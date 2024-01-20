#include <QCoreApplication>
#include <QApplication> // to run
#include "exercise.h"
#include "exercisereader.h"
#include "exercisewriter.h"
#include "exerciselist.h"
#include "exercisedialog.h"
#include "mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMapIterator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    exerciseList LIST;
//    LIST.txtToExerciseList("workouts.txt");

//    QMap<int,exercise>::const_iterator it;

//    for (it = LIST.getListOfExercises().constBegin();it != LIST.getListOfExercises().constEnd();++it)
//    {
//        qDebug() << it.value().toString() << '\n';
//    }

//    LIST.exerciseListToTxt("writtenFromExList.txt");


//    exerciseDialog dialog;
//    dialog.setWindowTitle("Add exercise");

//    exercise *newExercise = dialog.addExercise();
//    exerciseWriter writer("workouts.txt");
//    writer.writeItem(*newExercise);

//    if (newExercise != 0)
//    {
//        qDebug() << newExercise->toString() << '\n';
//    }

//    newExercise = dialog.changeExercise(newExercise);
//    qDebug() << newExercise->toString() << '\n';

//    exerciseReader reader("workouts.txt");
//    while (!reader.endOfFile())
//    {
//        exercise ex = reader.readItem();
//        exercise *newEx = &ex;
//        newEx = exerciseDialog::changeExercise(newEx);
//        qDebug() << newEx->toString() << '\n';
//    }

    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();

}
