#include <QApplication>
#include <paintdialog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintDialog *dialog = new PaintDialog;

    dialog->show();

    return a.exec();
}
