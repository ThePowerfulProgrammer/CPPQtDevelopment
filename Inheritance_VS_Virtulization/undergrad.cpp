#include "undergrad.h"


Undergrad::Undergrad(QString name, long id, QString major, int year) :
    Student(name,id, major, year)
{

}

QString Undergrad::getClassName() const
{
    return "Undergrad";
}
