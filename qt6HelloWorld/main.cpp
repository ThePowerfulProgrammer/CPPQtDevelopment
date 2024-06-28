#include <QApplication>
#include <QDebug>
#include <QDialog>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "Hello world" << "\n";
    QDialog *dialog = new QDialog;
    dialog->setWindowTitle("Hello world Qt6");
    dialog->show();

    return a.exec();
}
