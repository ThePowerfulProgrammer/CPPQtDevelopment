#include <QApplication>
#include <QtSql/QSqlDatabase>

#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "There should be drivers here" << "\n";
    return a.exec();
}
