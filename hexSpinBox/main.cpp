#include <QApplication>
#include <QDialog>
#include <QLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include "hexspinbox.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDialog *dialog = new QDialog;
    HexSpinBox *spinBox = new HexSpinBox;


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(spinBox);
    layout->setGeometry(QRect(100,100,100,100));
    dialog->setLayout(layout);
    dialog->setFixedSize(400,400);
    dialog->show();

    return a.exec();
}
