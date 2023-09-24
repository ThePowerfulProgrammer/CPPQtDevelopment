#include <QApplication>
#include <QString>
#include <QLabel>
#include <QWidget>
#include <QDebug>
#include <QTextStream>
#include <QDate>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wid;
    qDebug() << "Size of widget: " << sizeof(wid) << " sizeof Qapplication: "
             << sizeof(a) ;
    QString message;
    QTextStream buf(&message);
    QTextStream cout(stdout,QIODevice::WriteOnly);

    buf << "A QWidget is " << sizeof(wid)
        << " bytes. \n A QObject is " << sizeof(QObject)
        << " bytes. \n A QApplication is " << sizeof(a)
        << " bytes. " ;
    cout << "Hello world" ;

    qDebug() << message;
    QLabel label(message);
    label.show();

    return a.exec();
}
