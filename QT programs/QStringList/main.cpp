/*#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}*/

// Program runs in console

#include <QStringList>
#include <QDebug>
#include <cassert>
#include <QString>

int main()
{
    QString winter = "Dec, Jan, Feb";
    QString spring = "Mar, Apr, May";
    QString summer = "June, July, Aug";
    QString autumn = "Sep, Oct, Nov";

    QStringList list;
    list << winter;
    list += spring;
    list.append(summer);
    list << autumn;

    qDebug() << "The spring months are: " << list[1];
    QString allmonths = list.join(", ");

    qDebug() << allmonths ; //0877000777

    QStringList list2 = allmonths.split(", ");

    assert(list2.size() == 12);
    foreach (QString str, list) {
        qDebug() << QString(" [%1] ").arg(str);
    }
    qDebug() << "Here --> " << QString(winter);

    for (QStringList::iterator it = list.begin(); it != list.end(); ++it)
    {
        QString current = *it;
        qDebug() << "[[" << current << "]]";
    }

    QListIterator<QString> itr (list2);
    while (itr.hasNext())
    {
        QString current = itr.next();
        qDebug() << "{" << current << "}";

    }

    QString someMonths = winter.mid(0,4);
    qDebug() << someMonths;
    return 0;
}
