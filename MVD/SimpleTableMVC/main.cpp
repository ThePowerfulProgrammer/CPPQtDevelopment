#include <QApplication>
#include "mydialog.h"
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("C:/Users/ashis/OneDrive/Desktop/Qt/MVD/SimpleTableMVC/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    myDialog *dialog = new myDialog;
    dialog->setStyleSheet(styleSheet);
    dialog->show();
    return a.exec();
}
