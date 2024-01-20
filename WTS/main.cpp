#include <QCoreApplication>
#include "workout.h"
#include "exercise.h"
#include <QDebug>
#include <QDate>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Test run 1" << "\n";

    workout w1("Upper A",QDate::currentDate());
    exercise ex("Bench Press", 3,8,90);
    w1.addExercise(ex);
    qDebug() << w1.getDate() << " " << w1.getName() << "\n";
    w1.exerciseList();
    return a.exec();
}
