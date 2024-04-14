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

    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(loadBtn);
    firstRow->addSpacing(30);
    firstRow->addWidget(processBtn);

    // 2nd row
    textEdit = new QTextEdit(this);

    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(textEdit);

    // S & S
    connect(loadBtn, SIGNAL(clicked()), this, SLOT(loadData()));
    connect(processBtn, SIGNAL(clicked()), this, SLOT(processData()));


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
        cursor->select(QTextCursor::Document);
    }
}

void SearchDialog::processData()
{
    // use cursor to capatalise regexMatch
    bool n = cursor->movePosition(QTextCursor::WordRight,QTextCursor::KeepAnchor,5);

    qDebug() << n ;
    QFont font;
    font.setCapitalization(QFont::AllUppercase);

    QTextCharFormat format;
    format.setFont(font);

    cursor->setCharFormat(format);

    textEdit->setDocument(cursor->document());
    textEdit->setReadOnly(true);
}
