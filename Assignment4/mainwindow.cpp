#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QTextEdit>
#include <QDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QInputDialog>


mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent),dataChanged(false)
{

    // set win title
    setWindowTitle(tr("Stock"));

    resize(800,600);

    toolbar = new QToolBar(this);
    addToolBar(toolbar);

    QAction *open = new QAction(tr("&O"),this);
    QAction *save = new QAction(tr("&S"),this);
    QAction *exit = new QAction(tr("&X"),this);


    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(exit);

    connect(open,&QAction::triggered,this, &mainWindow::openDialog);
    connect(save,&QAction::triggered,this,&mainWindow::saveFile);
    connect(exit, &QAction::triggered,this, &mainWindow::exitApplication);

    // change css
    toolbar->setStyleSheet("QToolButton {color:#000000;} QTooolButton:hover {color:blue} QToolButton {border: 1px solid #000}");


    QAction *add = new QAction(tr("&A"),this);
    QAction *change = new QAction(tr("&C"),this);
    QAction *remove = new QAction(tr("&R"),this);

    toolbar->addAction(add);
    toolbar->addAction(change);
    toolbar->addAction(remove);

    connect(add,&QAction::triggered,this, &mainWindow::onAddItem);
    connect(change,&QAction::triggered,this,&mainWindow::onChangeItem);
    connect(remove, &QAction::triggered,this, &mainWindow::removeFunction);


    fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(open);
    fileMenu->addAction(save);
    fileMenu->addSeparator();
    fileMenu->addAction(exit);

    fileMenu = menuBar()->addMenu(tr("Edit"));


}

void mainWindow::openDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Text File"), "",
        tr("Text Files (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }

        QTextStream in(&file);
        QTextEdit *textEdit = new QTextEdit(this);
        QString data = "           Barcode \t            Description \t  Stock \t   Price \n";
        data += in.readAll();
        textEdit->setText(data);
        textEdit->setReadOnly(true);
        setCentralWidget(textEdit);
    }
}

void mainWindow::onAddItem()
{
    Item* item = ItemDialog::addItem();
    ItemList list;
    // We process the item
    if(item != 0)
    {
        // Process the new item
        list.listOfItems.insert(item->getPrice(),*item); // add items until we have to write

    }
}

void mainWindow::saveFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Text File"), "",
        tr("Text Files (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        ItemList LIST;
        LIST.itemListToTxt(fileName);
        LIST.listOfItems.clear(); // clear all items
        dataChanged = !dataChanged; // SWITCHHH not operator come in clutch :)
    }

}

void mainWindow::exitApplication()
{
    // Check if data has been changed since the last save
    if (dataChanged == false)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Unsaved Changes", "Do you want to save the changes before exiting?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if (reply == QMessageBox::Yes)
        {
            saveFile(); // Save the data
        }
        else if (reply == QMessageBox::Cancel)
        {
            // User chose to cancel, so don't exit
            return;
        }
        // If user chose No, simply exit without saving
    }

    // Exit the application
    close();
}


void mainWindow::onChangeItem()
{
    // Get the barcode from the user
    QString barcode = QInputDialog::getText(this, "Enter Barcode", "Barcode:", QLineEdit::Normal, "");
    ItemList List;
    if (!barcode.isEmpty())
    {
        // Search for the item using the barcode
        Item* itemToChange = List.searchByBarcode(barcode);
        qDebug() << "Change item";
        if (itemToChange)
        {
            // If item found, open the change dialog
            Item* changedItem = ItemDialog::changeItem(itemToChange);

            if (changedItem) {
                // Update the item if changes were made
                *itemToChange = *changedItem;
                dataChanged = true; // Mark data as changed
            }
        }
        else
        {
            QMessageBox::information(this, "Item Not Found", "No item found with the provided barcode.");
        }
    }
}

void mainWindow::removeFunction()
{
    // Get the barcode from the user
    QString barcode = QInputDialog::getText(this, "Enter Barcode", "Barcode:", QLineEdit::Normal, "");

    if (!barcode.isEmpty())
    {
        // Search for the item using the barcode
        ItemList LIST;
        Item* itemToRemove = LIST.searchByBarcode(barcode);

        if (itemToRemove)
        {
            // Ask for confirmation before deleting
            QMessageBox::StandardButton confirmDelete;
            confirmDelete = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to delete this item?",
                                                  QMessageBox::Yes | QMessageBox::No);

            if (confirmDelete == QMessageBox::Yes)
            {
                // Delete the item
                LIST.removeItem(itemToRemove);
                dataChanged = true; // Mark data as changed
            }
        } else
        {
            QMessageBox::information(this, "Item Not Found", "No item found with the provided barcode.");
        }
    }
}
