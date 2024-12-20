#include "gradstudent.h"



GradStudent::GradStudent(QString nm, long id, QString major, int yr, GradStudent::Support support)
    : Student(nm,id,major, yr), m_Support(support)
{

}

QString GradStudent::getClassName() const
{
    return "GradStudent";
}

QString GradStudent::supportStr(Support str)
{
    QString supportStr = QString("%1").arg(str);
    return supportStr;
}

QString GradStudent::toString() const
{
    QString result;
     QTextStream os(&result);
     os <<  Student::toString()
     << "\n  [Support: "
     << supportStr(m_Support)
     << " ]\n";
     return result;
}







