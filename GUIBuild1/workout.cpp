#include "workout.h"
#include <fstream> // file access

Workout::Workout()
{
    name = "";
    dateCreated  = QDate::currentDate();
}

Workout::Workout(QString n)
{
    name = n;
    dateCreated  = QDate::currentDate();
}

Workout::Workout(const Workout &wk)
{
    name = wk.name;
    for (int i=0;i<wk.exerciseList.size();i++)
        {
            exerciseList.push_back(wk.exerciseList[i]);
        }
    dateCreated  = QDate::currentDate();
}

void Workout::addExercise(Exercise ex)
{
    exerciseList.push_back(ex);
}

QString Workout::getName()
{
    return name;
}

QList<Exercise> Workout::getExercises()
{
    return exerciseList;
}

QDate Workout::getDate()
{
    return dateCreated;
}

//void Workout::writeToFile(QString fname)
//{
//    ofstream outFile(fname, ios::app);
//    if (outFile.is_open())
//        {
//            for (int i=0;i<exerciseList.size();i++)
//                {
//                    outFile << this->getDate() << " ";
//                    outFile << exerciseList[i].toString() << "\n";
//                }
//            outFile.close();
//        }
//    else cout << "Unable to open file";

//}

//void Workout::readFromFile(QString fname)
//{
//    ifstream inputFile(fname);
//    QString line;
//    QString date;
//    QString name;

//    if (inputFile.is_open())
//    {
//        while (getline(inputFile, line))
//        {
//            date = line.substr(0,24);
//            name = line.substr(25);

//            cout << date << "-->" << name << endl;
//        }
//        inputFile.close();
//    }
//    else cout << "Unable to open File!";
//}

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
