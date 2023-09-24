#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QTextEdit>
#include <QDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), dataChanged(false)
{
    // Set the window title
    setWindowTitle(tr("Stock editor"));

    // Set the window size
    resize(800, 600);



    // Create a toolbar and connect it
    toolbar = new QToolBar(this);
    addToolBar(toolbar);

    // Actions for the toolbar
    QAction *open = new QAction(tr("&O"), this);
    QAction *save = new QAction(tr("&S"), this);
    QAction *exit = new QAction(tr("&X"), this);

    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(exit);

    // Connect actions to slots or functions O,S,X
      connect(open, &QAction::triggered, this, &MainWindow::openDialog);
      connect(save, &QAction::triggered, this, &MainWindow::saveFile);
      connect(exit, &QAction::triggered, this, &MainWindow::exitApplication);

    // Change CSS
    toolbar->setStyleSheet("QToolButton { color: #000000; } QToolButton:hover { color: #aaa; } QToolButton { border: 1px solid #000; }");



    // More actions for our toolbar
    QAction *add = new QAction(tr("&A"), this);
    QAction *change = new QAction(tr("&C"), this);
    QAction *remove = new QAction(tr("&R"), this);

    toolbar->addAction(add);
    toolbar->addAction(change);
    toolbar->addAction(remove);

    // Connect actions to slots or functions A,C,R
      connect(add, &QAction::triggered, this, &MainWindow::onAddItem);

      connect(change, &QAction::triggered, this, &MainWindow::onchangeItem);
      connect(remove, &QAction::triggered, this, &MainWindow::removeFunction);

    // Create a File menu
    fileMenu = menuBar()->addMenu(tr("&File"));

    // Add actions to the File menu
    fileMenu->addAction(open);
    fileMenu->addAction(save);
    fileMenu->addSeparator();  // Add a separator
    fileMenu->addAction(exit);

    fileMenu = menuBar()->addMenu(tr("Edit"));


}

void MainWindow::openDialog()
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

void MainWindow::onAddItem()
{
    Item* item = ItemDialog::addItem();
    itemList list;
    // We process the item
    if(item != 0)
    {
        // Process the new item
        list.listOfItems.insert(item->getPrice(),*item); // add items until we have to write

    }
}

void MainWindow::saveFile()
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
        itemList LIST;
        LIST.itemListToTxt(fileName);
        LIST.listOfItems.clear(); // clear all items
        dataChanged = !dataChanged; // SWITCHHH not operator come in clutch :)
    }

}

void MainWindow::exitApplication()
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


void MainWindow::onchangeItem()
{
    // Get the barcode from the user
    QString barcode = QInputDialog::getText(this, "Enter Barcode", "Barcode:", QLineEdit::Normal, "");
    itemList List;
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

void MainWindow::removeFunction()
{
    // Get the barcode from the user
    QString barcode = QInputDialog::getText(this, "Enter Barcode", "Barcode:", QLineEdit::Normal, "");

    if (!barcode.isEmpty())
    {
        // Search for the item using the barcode
        itemList LIST;
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


