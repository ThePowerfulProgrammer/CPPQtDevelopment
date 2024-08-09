#include "person.h"
#include <QDebug>


Person::Person(QObject *parent) : QObject(parent)
{

}

Person::Person(const QString &names, const QString &favoritecolor, const int &age, const int ss,QObject *parent):
    QObject(parent),m_names(names),m_favoriteColor(favoritecolor),m_age(age), socialScore(ss)
{

}

QString Person::names() const
{
    return m_names;
}

QString Person::favoriteColor() const
{
    return m_favoriteColor;
}

int Person::age() const
{
    return m_age;
}

void Person::setNames(QString names)
{
    if (m_names == names)
        return;

    m_names = names;
    emit namesChanged(m_names);
}

void Person::setFavoriteColor(QString favoriteColor)
{
    qDebug() << "Favorite color called";
    if (m_favoriteColor == favoriteColor)
        return;

    m_favoriteColor = favoriteColor;
    emit favoriteColorChanged(m_favoriteColor);
}

void Person::setAge(int age)
{
    if (m_age == age)
        return;

    m_age = age;
    emit ageChanged(m_age);
}
int Person::getSocialScore() const
{

    return socialScore;
}

void Person::setSocialScore(int value)
{
    if (socialScore == value)
    {
        return;
    }

    socialScore = value;

}

