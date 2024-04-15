#include <QApplication>
#include "softwarereviewdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SoftwareReviewDialog *dialog = new SoftwareReviewDialog;
    dialog->show();
    return a.exec();
}
