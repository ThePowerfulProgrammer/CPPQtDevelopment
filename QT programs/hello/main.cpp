#include <QCoreApplication>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString winter = "December, January, February";
    QString spring = "March, April, May";
    QString summer = "June, July, August";
    QString fall = "September, October, November";

    QStringList list;
    list << winter;
    list += spring;
    list.append(summer);
    list << fall;

    qDebug() << "The spring months are: " << list[1];

    QString allMonths = list.join(", ");
    qDebug() << allMonths ;

    return a.exec();
}
