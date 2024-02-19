#include <QApplication>
#include <QFile>
#include "softwarereviewdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SoftwareReviewDialog *dialog = new SoftwareReviewDialog;
    // style
    QFile file("C:/Users/ashis/OneDrive/Desktop/Qt/COS3711/assignment1_question1/stylesheet.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    dialog->setStyleSheet(styleSheet);
    dialog->show();

    return app.exec();
}
