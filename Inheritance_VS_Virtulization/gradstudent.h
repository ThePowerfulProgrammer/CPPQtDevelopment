#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H
#include <QDebug>
#include <QString>
#include "student.h"

class GradStudent : public Student
{
public:

    enum Support {ta, ra, fellowship, other};

    GradStudent(QString nm, long id, QString major,
                int yr,Support support);
    QString getClassName() const;
    QString toString() const;

protected:
    static QString supportStr(Support str);

private:
    Support m_Support;

};

#endif // GRADSTUDENT_H
