#include "musicdialog.h"
#include <QLabel>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QLineEdit>
#include <QString>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QMessageBox>
#include <QHeaderView>
#include <QDebug>
#include <QSpacerItem>
#include "colordelegate.h"
#include "progressbardelegate.h"
#include "doubledelegate.h"

MusicDialog::MusicDialog(QWidget *parent) : QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint)
{
    // Create the first row
    composerLabel = new QLabel("Composer", this);
    albumTitleLabel = new QLabel("Album Title",this);
    replacementCostLabel = new QLabel("Replacement Cost (R) ", this);
    ratingLabel = new QLabel("Rating", this);


    // Create the 2nd row
    addComposer = new QLineEdit(this);
    addComposer->setFocus();
    addComposer->setPlaceholderText("Composer");

    addAlbum = new QLineEdit(this);
    addAlbum->setPlaceholderText("Album");

    addReplacement = new QDoubleSpinBox(this);
    addReplacement->setMinimum(0.00);
    addReplacement->setMaximum(999.99);

    addRating = new QSpinBox(this);
    addRating->setMinimum(0);
    addRating->setMaximum(10);

    addButton = new QPushButton("Add", this);


    // create 4 vertical layouts
    QVBoxLayout *firstCol = new QVBoxLayout;
    firstCol->addWidget(composerLabel);
    firstCol->addWidget(addComposer);

    QVBoxLayout *secondCol =  new QVBoxLayout;
    secondCol->addWidget(albumTitleLabel);
    secondCol->addWidget(addAlbum);

    QVBoxLayout *thirdCol = new QVBoxLayout;
    thirdCol->addWidget(replacementCostLabel);
    thirdCol->addWidget(addReplacement);

    QVBoxLayout *fourthCol = new QVBoxLayout;
    fourthCol->addWidget(ratingLabel);
    fourthCol->addWidget(addRating);

    // Create 1 horizontal layout
    QHBoxLayout *firstRow =  new QHBoxLayout;
    firstRow->addLayout(firstCol);
    firstRow->addLayout(secondCol);
    firstRow->addLayout(thirdCol);
    firstRow->addLayout(fourthCol);
    firstRow->addWidget(addButton);



    //  2nd row create my model and set the table :^)
    model = new QStandardItemModel(this);

    QStringList labels;
    labels << "Composer" << "Album Title" << "Replacement Cost (R)" << "Rating";
    model->setHorizontalHeaderLabels(labels);

    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setShowGrid(true);
    tableView->setSortingEnabled(true);
    tableView->setColumnWidth(2,tableView->columnWidth(2)+100);
    tableView->horizontalHeader()->setStretchLastSection(true);


    // set delegates
    ColorDelegate *colorDelegate = new ColorDelegate(this);
    tableView->setItemDelegate(colorDelegate);

    ProgressBarDelegate *bar = new ProgressBarDelegate(this);
    tableView->setItemDelegateForColumn(3,bar);

//    DoubleDelegate *dd = new DoubleDelegate(this);
//    tableView->setItemDelegateForColumn(2, dd);

    // 2nd row
    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(tableView);

    connect(addButton, SIGNAL(clicked()), this, SLOT(addDate()));

    // 3rd row
    deleteButton = new QPushButton("Delete", this);
    QHBoxLayout *thirdRow= new QHBoxLayout;
    thirdRow->addStretch(50);
    thirdRow->addWidget(deleteButton, Qt::AlignRight);


    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteDate()));

    // main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);


    setWindowTitle("My Music Dialog");
    setLayout(mainLayout);

}

void MusicDialog::addDate()
{

    if (!addComposer->text().isEmpty() && !addAlbum->text().isEmpty() && addReplacement->value() != 0.00 && addRating->value() != 0)
    {
        // I want to add a new row to my model, I will use the indiviual widgets I have access to
        // Get the values from the widgets
        QString composer_text = addComposer->text();
        QString album_text = addAlbum->text();
        double replacement_value = addReplacement->value();
        int rating_value = addRating->value();



        addComposer->clear();
        addComposer->setPlaceholderText("Composer");
        addComposer->setFocus();
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
    else
    {
        QMessageBox::information(this, "Values missing", "Add Appropriate Data in the forms");
    }
}

void MusicDialog::deleteDate()
{
    if (model->rowCount() > 0)
    {
        model->removeRow(model->rowCount()-1);
    }
    else
    {
        QMessageBox::information(this,"No data", "Cannot remove that which does not exist");

    }

}

MusicDialog::~MusicDialog()
{

}
