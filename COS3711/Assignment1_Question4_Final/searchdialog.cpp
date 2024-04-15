#include "searchdialog.h"
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QFont>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QTextDocument>
#include <QRegularExpression>

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent ,Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint)
{
    // row 1
    loadBtn = new QPushButton("Load",this);
    processBtn = new QPushButton("Process",this);
    loadBtn->setDefault(true);
    tempBtn = new QPushButton("Regex",this);

    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(loadBtn);
    firstRow->addSpacing(30);
    firstRow->addWidget(processBtn);
    firstRow->addWidget(tempBtn);

    // 2nd row
    textEdit = new QTextEdit(this);

    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(textEdit);

    // S & S
    connect(loadBtn, SIGNAL(clicked()), this, SLOT(loadData()));
    connect(processBtn, SIGNAL(clicked()), this, SLOT(processData()));
    connect(tempBtn, SIGNAL(clicked()), this, SLOT(processRegex()));


    // main display
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);

    setLayout(mainLayout);
    setWindowTitle("Search");
    setFixedHeight(sizeHint().height());
    resize(300, height());
}

void SearchDialog::loadData()
{
    // open a txt file

    QString fileName = QFileDialog::getOpenFileName(this,"Open text file", QDir::currentPath(),"Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty())
    {
        QMessageBox::information(this,"File error", "Select a different file");
        return;
    }
    else
    {
        // open file for processing
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Unable to process file", file.errorString());
            return;
        }

        // read contents
        QTextStream in(&file);
        QString data;

        data += in.readAll();
        // clear old data and set new data
        textEdit->clear();
        textEdit->setText(data);

        // use textEdit to set the data for required members used in processData()
        document = new QTextDocument;
        document = textEdit->document();

        cursor = new QTextCursor(document);
    }
}

void SearchDialog::processData()
{
    // use cursor to capatalise regexMatch
    qDebug() << "Anchor " << cursor->anchor() << "Pos: " << cursor->position() << "\n";

    bool n = cursor->movePosition(QTextCursor::NextWord,QTextCursor::KeepAnchor,7);

    qDebug() << n << " Anchor" << cursor->anchor() << " Pos" << cursor->position();


    QFont font;
    font.setCapitalization(QFont::AllUppercase);

    QTextCharFormat format;
    format.setFont(font);

    cursor->setCharFormat(format);

    textEdit->setDocument(cursor->document());

    cursor->setPosition(cursor->position(),QTextCursor::MoveAnchor);

    cursor->movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor, 12);

    qDebug() << n << " Anchor" << cursor->anchor() << " Pos" << cursor->position();
    cursor->setCharFormat(format);
    textEdit->setDocument(cursor->document());
    textEdit->setReadOnly(true);
}

void SearchDialog::processRegex()
{
    QRegularExpression re;
    re.setPattern("(\\d{3}-\\d{3}-\\d{4}|\\d{3}-\\d{7}|\\d{10}|\\(\\d{3}\\)\\d{3}-\\d{4}|\\(\\d{3}\\)\\d{7})|\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");

    QRegularExpressionMatchIterator matchIterator = re.globalMatch(cursor->document()->toPlainText());
    while (matchIterator.hasNext())
    {
        QRegularExpressionMatch match = matchIterator.next();
        qDebug() << "Match at: " << match.capturedStart();
        qDebug() << " Match: " << match.captured(0) << "\n";
        cursor->setPosition(match.capturedStart(),QTextCursor::MoveAnchor);
        qDebug() << "Anchor " << cursor->anchor() << "Pos: " << cursor->position() << "\n";
        cursor->setPosition(match.capturedEnd(),QTextCursor::KeepAnchor);
        qDebug() << "Anchor " << cursor->anchor() << "Pos: " << cursor->position() << "\n";
        QTextCharFormat format;
        format.setFontWeight(50);
        QFont font;
        font.setBold(true);
        format.setFont(font);
        cursor->setCharFormat(format);
        textEdit->setDocument(cursor->document());
    }



}

