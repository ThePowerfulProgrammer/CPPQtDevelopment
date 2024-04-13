#include <QApplication>
#include "searchdialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SearchDialog *dialog = new SearchDialog;

    dialog->show();

    return a.exec();
}
