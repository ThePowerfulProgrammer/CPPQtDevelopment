#include "notepad.h"
#include "ui_notepad.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

notePad::notePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notePad)
{
    ui->setupUi(this);
}

notePad::~notePad()
{
    delete ui;
}

void notePad::on_quitButton_clicked()
{
    qApp->quit();
}

// open a file
/*

The static getOpenFileName() function displays a modal file dialog.
It returns the file path of the file selected, or an empty string if the user canceled the dialog.

If we have a file name, we try to open the file with open(), which returns true if the file could be opened.
We will not go into error handling here, but you can follow the links from the learn more section.
If the file could not be opened, we use QMessageBox to display a dialog with an error message (see the QMessageBox class description for further details).

Actually reading in the data is trivial using the QTextStream class, which wraps the QFile object.
The readAll() function returns the contents of the file as a QString.
The contents can then be displayed in the text edit. We then close() the file to return the file descriptor back to the operating system.

We now use the function tr() around our user visible strings.
This function is necessary when you want to provide your application in more than one language (for example, English and Chinese).
We will not go into details here, but you can follow the Qt Linguist link from the learn more table.

*/
void notePad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QString(),
                                                    tr("Text files (*.txt);;C++ Files (*.cpp *h)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();

    }

}

// Save a file

void notePad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),QString(),
                                                    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this,tr("Error Sys Malfunction"), tr("Could not open file"));
        }
        else
        {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}
