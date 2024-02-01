#include <QCoreApplication>
#include <QApplication>
#include "exercise.h"
#include "workout.h"
#include "workoutwriter.h"
#include "workoutreader.h"
#include <QDebug>
#include <QTableView>
#include <QStandardItem>
#include <QStringList>

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

//    qDebug() << w1.getName() << "\n";
//    qDebug() << w1.getDate() << "\n";
//    for (int i=0;i<w1.getExercises().size();i++)
//    {
//        qDebug() << w1.getExercises()[i].toString() << "\n";
//    }

//    workoutWriter writer("test.txt");
//    writer.writeWorkout(w1);

    workoutReader reader("test.txt");
    Workout test = reader.readWorkout("Upper A Copy");


    qDebug() << test.getName() << "\n";
    for (int i=0;i<test.getExercises().size();i++)
    {
        qDebug() << test.getExercises()[i].toString() << " --- "<< "\n";
    }


    // Create a QTableView object
    QTableView *tableView = new QTableView();

    // Create a QStandardItemModel object and set it as the model for the QTableView object
    QStandardItemModel *model = new QStandardItemModel();
    tableView->setModel(model);

    // Set the number of rows and columns for the QStandardItemModel object
    model->setRowCount(3);
    model->setColumnCount(2);

    QStringList colLabels;
    colLabels.append("Name");
    colLabels.append("Sets");

    model->setHorizontalHeaderLabels(colLabels);


    qDebug() << test.getExercises()[1].getSets() << "\n";
    // Populate the QStandardItemModel object with data
    model->setItem(0, 0, new QStandardItem(test.getExercises()[0].getName()));
    model->setItem(0, 1, new QStandardItem(QString::number(test.getExercises()[0].getSets())));
    model->setItem(1, 0, new QStandardItem(test.getExercises()[1].getName()));
    model->setItem(1, 1, new QStandardItem(QString::number(test.getExercises()[1].getSets())));
    model->setItem(2, 0, new QStandardItem(test.getExercises()[3].getName()));
    model->setItem(2, 1, new QStandardItem(QString::number(test.getExercises()[3].getSets())));



    // Set the QTableView object's model to the QStandardItemModel object
    tableView->setModel(model);

    // Optionally, customize the QTableView object's appearance and behavior using its properties, functions, slots, and methods
    tableView->setWindowTitle("QTableView Example");
    tableView->resize(400, 300);
    tableView->show();



    return a.exec();
}
