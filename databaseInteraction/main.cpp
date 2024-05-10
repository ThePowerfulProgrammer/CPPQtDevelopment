#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QSqlError>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("testdbs");
    db.setUserName("root");
    db.setPassword("Powerful_Sql");

    if(db.open())
    {
        qDebug() << "Connected to the database.";

        QSqlQuery query;
        if(query.exec("SHOW TABLES"))
        {
            while(query.next())
            {
                qDebug() << query.value(0).toString();
            }
        } else
        {
            qDebug() << "Query failed: " << query.lastError();
        }

        db.close();
    }
    else
    {
        qDebug() << "Connection failed: " << db.lastError();
    }

    return a.exec();
}
