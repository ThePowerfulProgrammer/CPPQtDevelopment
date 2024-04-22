#include <QApplication>
#include "searchdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    searchDialog *dialog = new searchDialog;
    dialog->show();
    return a.exec();
}
