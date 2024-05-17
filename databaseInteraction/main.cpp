#include <QApplication>

#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QtSql>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setDatabaseName("testdbs");
    db.setPassword("Powerful_Sql");

    qDebug() << QSqlDatabase::drivers() << " \n";

    if(db.open())
    {
        qDebug() << "Connected to the database.";


        db.close();
    }
    else
    {
        qDebug() << "Connection failed: ";
    }



    return a.exec();
}
