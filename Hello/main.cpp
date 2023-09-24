#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel* label = new QLabel("Hello Qt World");
    label->setGeometry(250,200,250,200);
    label->show();
    return app.exec();
}

