#include "mydialog.h"
#include <QDebug>
#include <QStandardItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>
#include <QList>

myDialog::myDialog(QWidget *parent): QDialog(parent)
{
    // create the first horizontal box
    composerLabel = new QLabel("Composer",this);
    albumTitle = new QLabel("Album title",this);
    replacementCost = new QLabel("Replacement cost(R)",this);
    rating = new QLabel("Rating",this);


    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(composerLabel);
    firstRow->addSpacing(30);
    firstRow->addWidget(albumTitle);
    firstRow->addWidget(replacementCost);
    firstRow->addWidget(rating);

    // create the 2nd row
    addComposer = new QLineEdit(this);
    addComposer->setPlaceholderText("Composer");

    addAlbum = new QLineEdit(this);
    addAlbum->setPlaceholderText("Album");

    addReplacement = new QDoubleSpinBox(this);
    addReplacement->setMinimum(0.00);
    addReplacement->setMaximum(999.99);

    addRating = new QSpinBox(this);
    addRating->setMinimum(0);
    addRating->setMaximum(10);

    add = new QPushButton("Add",this);

    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(addComposer);
    secondRow->addWidget(addAlbum);
    secondRow->addWidget(addReplacement);
    secondRow->addWidget(addRating);
    secondRow->addWidget(add);


    // 3rd row: Create my model add the data and set the tableview
    model = new QStandardItemModel(this);
    QStringList labels;
    labels << "Composer" << "Album title" << "Replacement cost(R)" << "Rating";
    model->setHorizontalHeaderLabels(labels);


    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setColumnWidth(2,tableView->columnWidth(2)+50);
    QHBoxLayout *thirdRow = new QHBoxLayout;
    thirdRow->addWidget(tableView);

    connect(add,SIGNAL(clicked()),this,SLOT(addData()));


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);


    setLayout(mainLayout);
}


void myDialog::addData()
{
    // I want to add a new row to my model, I will use the indiviual widgets I have access to
    // Get the values from the widgets
    QString composer_text = addComposer->text();
    QString album_text = addAlbum->text();
    double replacement_value = addReplacement->value();
    int rating_value = addRating->value();

    addComposer->clear();
    addComposer->setPlaceholderText("Composer");
    addAlbum->clear();
    addAlbum->setPlaceholderText("Album");
    addReplacement->setValue(0.00);
    addRating->setValue(0);

    // Create QStandardItem objects
    QStandardItem* composer_item = new QStandardItem(composer_text);
    QStandardItem* album_item = new QStandardItem(album_text);
    QStandardItem* replacement_item = new QStandardItem(QString::number(replacement_value));
    QStandardItem* rating_item = new QStandardItem(QString::number(rating_value));

    // Insert a new row into the model
    int row = model->rowCount();
    model->insertRow(row, QList<QStandardItem*>() << composer_item << album_item << replacement_item << rating_item);
}

myDialog::~myDialog()
{

}
