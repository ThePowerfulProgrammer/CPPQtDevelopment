#ifndef UNDERGRAD_H
#define UNDERGRAD_H
#include <QString>
#include <QDebug>
#include "student.h"

class Undergrad : public Student
{
public:
    Undergrad(QString name, long id, QString major, int year);
    QString getClassName() const;
};

#endif // UNDERGRAD_H
