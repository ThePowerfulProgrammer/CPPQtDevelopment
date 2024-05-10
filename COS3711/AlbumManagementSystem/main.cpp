#include <QApplication>
#include "musicdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MusicDialog *dialog = new MusicDialog;
    dialog->show();
    return a.exec();
}
