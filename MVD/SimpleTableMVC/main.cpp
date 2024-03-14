#include <QApplication>
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    myDialog *dialog = new myDialog;
    dialog->show();
    return a.exec();
}
