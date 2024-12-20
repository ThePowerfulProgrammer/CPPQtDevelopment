#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

class Student
{
public:
    Student(QString nm, long id, QString m_Major, int year = 1);
    virtual ~Student();

    virtual QString getClassName() const;
    virtual QString toString() const;

    QString yearString() const;



    QString getMName() const;
    void setMName(const QString &value);

    QString getMMajor() const;
    void setMMajor(const QString &value);

    int getMStudentId() const;
    void setMStudentId(int value);

    int getMYear() const;
    void setMYear(int value);

protected:
    int mYear;

private:

    QString mName;
    QString mMajor;
    int mStudentId;

};

#endif // STUDENT_H
