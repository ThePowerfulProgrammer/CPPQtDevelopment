#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello world");
    label->setWindowTitle("This is a title");
    label->resize(200,150);
    label->show();
    return app.exec();

    //:-1: error: cannot open output file debug\basic_build.exe: Permission denied
    // issue: Program may be still running as it does not have regular "press any button to exit"

}
