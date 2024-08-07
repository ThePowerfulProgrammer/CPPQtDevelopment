#include "searchdialog.h"

#include <QTextEdit>
#include <QPushButton>
#include <QTextDocument>
#include <QTextCursor>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include <QFont>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <QDebug>

searchDialog::searchDialog(QWidget *parent) :
    QDialog(parent,Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint)
{
    // row 1
    loadBtn = new QPushButton("Load", this);
    processBtn = new QPushButton("Process", this);
    processBtn->setDisabled(true);
    loadBtn->setDefault(true);

    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(loadBtn);
    firstRow->addSpacing(10);
    firstRow->addWidget(processBtn);

    // row 2
    textEdit = new QTextEdit(this);
    textEdit->setText("Load a file using the Load button \nFind pattern matches using the process Button");
    textEdit->setReadOnly(true);

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
    setWindowTitle("Search RegeX");
    setFixedHeight(sizeHint().height()+100);
    resize(500, height()+100);
}

void searchDialog::loadData()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open text file", QDir::currentPath(), "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "File error", "Select a different file");
        return;
    }
    else
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Unable to process file", file.errorString());
            return;
        }

        QTextStream in(&file);
        QString data;

        data += in.readAll();

        textEdit->clear();
        textEdit->setText(data);
        textEdit->setReadOnly(true);

        document  = new QTextDocument;
        document = textEdit->document();

        cursor = new QTextCursor(document);
        qDebug() << "File has been loaded and is ready for processing" << "\n";
        processBtn->setEnabled(true);
    }

}


void searchDialog::processData()
{
    qDebug() << "In function \n";
    QRegularExpression re;
    re.setPattern("(\\d{3}-\\d{3}-\\d{4}|\\d{3}-\\d{7}|\\d{10}|\\(\\d{3}\\)\\d{3}-\\d{4}|\\(\\d{3}\\)\\d{7})|\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");

    QRegularExpressionMatchIterator matchIterator = re.globalMatch(cursor->document()->toPlainText());

    while (matchIterator.hasNext())
    {
        QRegularExpressionMatch match = matchIterator.next();

        cursor->setPosition(match.capturedStart(), QTextCursor::MoveAnchor);
        cursor->setPosition(match.capturedEnd(), QTextCursor::KeepAnchor);

        QTextCharFormat format;
        format.setFontWeight(69);

        QFont font;
        font.setBold(true);
        format.setFont(font);
        cursor->setCharFormat(format);

        textEdit->setDocument(cursor->document());
    }

    qDebug() << "File contents have been processed and matches should appear in bold :^) " << "\n";
}












