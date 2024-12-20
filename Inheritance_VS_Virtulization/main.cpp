#include <QApplication>
#include <QDebug>
#include "student.h"
#include "undergrad.h"
#include "gradstudent.h"
#include <QTextStream>
#include <QDebug>

static QTextStream cout(stdout, QIODevice::WriteOnly);


/* A student is still a student */
/* now in the parent class dynamic binding has been turned on */
void graduate(Student *student)
{
    qDebug() << "\nThe following "
         << student->getClassName()
         << " has graduated\n"
         << student->toString() << "\n";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    GradStudentis a Student,in the sense that a GradStudent object can be used
//    wherever a Student object can be used. The client code shown in this example
//    creates some instances and performs operations on a GradStudent or an
//    Undergrad instance directly and also indirectly, through pointers.

    Undergrad us("Frodo", 5562, "Ring Theory", 4);
    GradStudent gs("Bilbo", 3029, "History", 6, GradStudent::fellowship);

    qDebug() << "Here is the data for the two students:\n";
    qDebug() << gs.toString() << "\n";
    qDebug() << us.toString() << "\n";

    qDebug() << "\nHere is what happens when they graduate:\n";

    graduate(&us);
    graduate(&gs);




    return a.exec();
}
