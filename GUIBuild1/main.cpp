#include <QCoreApplication>
#include <QApplication>
#include "exercise.h"
#include "workout.h"
#include "workoutwriter.h"
#include "workoutreader.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Exercise ex("Bench press",3,5,80);
    Exercise ex1(ex);
    Exercise ex2;
    ex2 = ex1;
    Exercise ex3("Squat",3,5,90);

//    qDebug() << ex.toString() << "\n";
//    qDebug() << ex1.toString() << "\n";
//    qDebug() << ex2.toString() << "\n";
//    ex2.display();

    Workout w1("Upper A");
    w1.addExercise(ex);
    w1.addExercise(ex1);
    w1.addExercise(ex2);
    w1.addExercise(ex3);

    qDebug() << w1.getName() << "\n";
    qDebug() << w1.getDate() << "\n";
    for (int i=0;i<w1.getExercises().size();i++)
    {
        qDebug() << w1.getExercises()[i].toString() << "\n";
    }

//    workoutWriter writer("test.txt");
//    writer.writeWorkout(w1);

    workoutReader reader("test.txt");
    reader.readWorkout();

    return a.exec();
}
