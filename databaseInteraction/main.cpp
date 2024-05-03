#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("test");
    db.setHostName("localhost");
    db.setDatabaseName("customdb");
    db.setUserName("mojito");
    db.setPassword("J0a1m8");
    bool ok = db.open();

    if (ok)
        qDebug() << "Connected to MySQL!";
    else
        qDebug() << "Failed to connect to MySQL.";

    return a.exec();
}
