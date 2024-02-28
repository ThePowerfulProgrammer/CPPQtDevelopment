#include <QApplication> // required for our GUI app to build and run
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include "softwarereviewdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoftwareReviewDialog* dialog = new SoftwareReviewDialog;

    dialog->show();

    return a.exec();
}
