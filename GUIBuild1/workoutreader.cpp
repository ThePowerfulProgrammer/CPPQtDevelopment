#include "workoutreader.h"
#include <QTextStream>
#include <QStringList>
#include <QDebug>

workoutReader::workoutReader(QString fname): inputFile(fname)
{
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
}

Workout workoutReader::readWorkout(QString name)
{
    QTextStream in(&inputFile); // read in file
    Workout tempWorkout(name);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        int date = line.indexOf("2024");
        int pos = line.indexOf("x");

        QString name = line.mid(date+5,pos-date-7);

        int sets = line.mid(pos-1,1).toInt();
        int reps = line.mid(pos+1,1).toInt();

        int at = line.indexOf("@");
        float workingWeight = line.mid(at+1).toFloat();
        Exercise ex(name,sets,reps,workingWeight);


        tempWorkout.addExercise(ex);
    }


    return tempWorkout;
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
