#include <QCoreApplication>


#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Powerful_Sql");
    db.setDatabaseName("testdbs");




    if (!db.open())
    {
        qDebug() << "Error: Unable to connect to database.";
        qDebug() << "Error Details:" << db.lastError().text();
        return 1;
    }

    QSqlQuery query;
    if (query.exec("SELECT * FROM exercise"))
    {
        while (query.next())
        {
            QString record = query.value(0).toString();
            qDebug() << "Record:" << record;
        }
    } else
    {
        qDebug() << "Query Error:" << query.lastError().text();
    }

    db.close();


    return a.exec();
}
