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

MusicDialog::MusicDialog(QWidget *parent) : QDialog(parent)
{
    // Create the first row
    composerLabel = new QLabel("Composer", this);
    albumTitleLabel = new QLabel("Album Title",this);
    replacementCostLabel = new QLabel("Replacement Cost (R) ", this);
    ratingLabel = new QLabel("Rating", this);

    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(composerLabel);
    firstRow->addWidget(albumTitleLabel);
    firstRow->insertSpacing(1,35);
    firstRow->addWidget(replacementCostLabel);
    firstRow->addWidget(ratingLabel);

    // Create the 2nd row
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

    addButton = new QPushButton("Add", this);

    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(addComposer);

    secondRow->addWidget(addAlbum);
    secondRow->addWidget(addReplacement);
    secondRow->addWidget(addRating);
    secondRow->addWidget(addButton);

    // 3rd row create my model and set the table :^)
    model = new QStandardItemModel(this);

    QStringList labels;
    labels << "Composer" << "Album Title" << "Replacement Cost (R)" << "Rating";
    model->setHorizontalHeaderLabels(labels);

    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setShowGrid(true);
    tableView->setSortingEnabled(true);
    tableView->horizontalHeader()->setStretchLastSection(true);


    QHBoxLayout *thirdRow = new QHBoxLayout;
    thirdRow->addWidget(tableView);

    connect(addButton, SIGNAL(clicked()), this, SLOT(addDate()));

    // 4th row
    deleteButton = new QPushButton("Delete", this);
    QHBoxLayout *fourthRow = new QHBoxLayout;
    fourthRow->addStretch(50);
    fourthRow->addWidget(deleteButton, Qt::AlignRight);


    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteDate()));

    // main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    mainLayout->addLayout(fourthRow);

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
