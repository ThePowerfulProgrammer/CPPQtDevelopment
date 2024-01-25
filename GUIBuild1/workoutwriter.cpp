#include "workoutwriter.h"
#include <QTextStream>
#include <QDate>

workoutWriter::workoutWriter(QString fname): outputFile(fname)
{
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);
}

void workoutWriter::writeWorkout(Workout &w)
{

    for (int i=0; i != w.getExercises().size();i++)
    {
        QTextStream(&outputFile) << w.getDate().toString() << " ";
        QTextStream(&outputFile) << w.getExercises()[i].toString() << '\r' << '\n';
    }

}

workoutWriter::~workoutWriter()
{
    outputFile.close();
}
