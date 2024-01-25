#include "workoutreader.h"
#include <QTextStream>
#include <QStringList>
#include <QDebug>

workoutReader::workoutReader(QString fname): inputFile(fname)
{
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
}

Workout workoutReader::readWorkout()
{
    QTextStream in(&inputFile); // read in file
    QString firstLine = in.readLine();

    int date = firstLine.indexOf("2024");
    int pos = firstLine.indexOf("x");

    QString test = firstLine.mid(date+5,pos-date);
    qDebug() << test << "\n";
    return Workout();
}

//Workout Workout::txtToWorkout(QString fname,string n)
//{
//    Workout tempWorkout(n);
//    ifstream inputFile(fname);
//    QString name;
//    QString line;

//    if (inputFile.is_open())
//        {
//            while (getline(inputFile, line))
//                {
//                    name = line.substr(25);
//                    Exercise tempEx(name);
//                    tempWorkout.exerciseList.push_back(tempEx);
//                }
//            inputFile.close();
//        }
//    else
//        {
//            cout << "File cannot be opened" << endl;
//        }
//    return tempWorkout;

//}


bool workoutReader::endOfFile()
{
    return inputFile.atEnd();
}

workoutReader::~workoutReader()
{
    inputFile.close();
}
