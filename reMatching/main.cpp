#include <QApplication>
#include <QRegularExpression>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QTextEdit>
#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QTextCursor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str("abbaa aba aaa bbb a a abbbbbbbbbba abababa");
    QRegularExpression re("ab+a");

    qDebug() << re.pattern() << "\n";
    qDebug() << str << "\n";

    QRegularExpressionMatchIterator matchIterator = re.globalMatch(str);
    while (matchIterator.hasNext())
    {
        QRegularExpressionMatch match = matchIterator.next();
        qDebug() << "Match found at position: " << match.capturedStart() << "\n";
        QString matched = match.captured(0);
        qDebug() << matched << "\n";
    }


    QRegularExpression re2;

    re2.setPattern("(\\d{3}-\\d{3}-\\d{4}|\\d{3}-\\d{7}|\\d{10}|\\(\\d{3}\\)\\d{3}-\\d{4}|\\(\\d{3}\\)\\d{7})|\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");


    QFile file("C:/Users/ashis/OneDrive/Desktop/Qt/reMatching/numbersAndEmails.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 1;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QRegularExpressionMatch match = re2.match(line);
        if (match.capturedStart() != -1)
        {
            qDebug() << match.captured(0) << "\n";
        }
        else
        {
            qDebug() << "No match" <<"\n";
        }
    }


    // open txt file and present contents on a dialog
    QString currentDir = QDir::currentPath();
    QString fileName = QFileDialog::getOpenFileName(0,
                                                    "Open File",
                                                    currentDir,
                                                    "Text Files (*.txt)");



    if (!fileName.isEmpty()) {
        qDebug() << "User selected file: " << fileName;
    } else {
        qDebug() << "User did not select a file.";
    }

    QFile myFile(fileName);

    if (!myFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Unable to open file",
            myFile.errorString());
        return 0;
    }

    QTextStream infile(&myFile);
    QTextEdit *textEdit = new QTextEdit;
    QString data;
    data += infile.readAll();
    textEdit->setText(data);
    textEdit->setReadOnly(true);

    QMainWindow *window = new QMainWindow;
    window->setCentralWidget(textEdit);
    window->show();

    return a.exec();
}
