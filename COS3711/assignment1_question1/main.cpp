#include <QApplication>

#include "softwarereviewdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SoftwareReviewDialog *dialog = new SoftwareReviewDialog;
    dialog->show();

    return app.exec();
}
