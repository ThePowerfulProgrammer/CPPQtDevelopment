#include "student.h"
#include <QDebug>
#include <QTextStream>

Student::Student(QString nm, long id, QString m_Major, int year) : mName(nm), mMajor(m_Major), mStudentId(id), mYear(year)
{

}



QString Student::getClassName() const
{
    return "Student";
}

QString Student::toString() const
{
    QString retVal;
    QTextStream outputStream(&retVal);
    outputStream << "[" << getClassName() << "]"
                    << " name: " << mName
                    << " Id: " << mStudentId
                    << " Year: " << yearString()
                    << " Major: " << mMajor;
    return retVal;

}


QString Student::yearString() const
{
    QString strYear = QString::number(mYear);
    return strYear;
}

QString Student::getMName() const
{
    return mName;
}

void Student::setMName(const QString &value)
{
    mName = value;
}
QString Student::getMMajor() const
{
    return mMajor;
}

void Student::setMMajor(const QString &value)
{
    mMajor = value;
}
int Student::getMStudentId() const
{
    return mStudentId;
}

void Student::setMStudentId(int value)
{
    mStudentId = value;
}
int Student::getMYear() const
{
    return mYear;
}

void Student::setMYear(int value)
{
    mYear = value;
}


Student::~Student()
{
    qDebug() << "Student class destructor \n";

}
