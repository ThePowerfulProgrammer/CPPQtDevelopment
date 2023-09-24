#include "notepad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    notePad w;
    w.show();

    return a.exec();
}
