#include "softwarereviewdialog.h"
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>

//Set the initial functionality of the variables
//Set the indiviual layouts of the vars
//Set up any signal and slot
//Set the layout


SoftwareReviewDialog::SoftwareReviewDialog(QWidget *parent) :
    QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint),
    hash(new QMultiHash<QString,QString>)
{

    // 1) Set up our widgets
    lineEdit = new QLineEdit;
    lineEdit->setPlaceholderText("Enter Software");
    lineEdit->setProperty("mandatoryField", true);
    nameLabel = new QLabel("Name");
    nameLabel->setBuddy(lineEdit);

    dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setCalendarPopup(true);
    dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));
    dateEdit->setMaximumDate(QDate::currentDate().addDays(365));
    dateEdit->setDisplayFormat("yyyy.MM.dd");
    dateLabel = new QLabel("Date");
    dateLabel->setBuddy(dateEdit);

    recommended = new QCheckBox("Recommend");

    add = new QPushButton("Add");
    add->setObjectName("add");

    display = new QPushButton("Display");
    display->setObjectName("display");



    // Signal and slots

    connect(add,SIGNAL(clicked()), this, SLOT(addSoftware()));
    connect(display,SIGNAL(clicked()), this, SLOT(displayList()));


    // Create the layout
    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(nameLabel);
    firstRow->addWidget(lineEdit);


    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(dateLabel);
    secondRow->addWidget(dateEdit);

    QHBoxLayout *thirdRow = new QHBoxLayout;
    thirdRow->addStretch();
    thirdRow->addWidget(recommended);


    QHBoxLayout *fourthRow = new QHBoxLayout;
    fourthRow->addWidget(add);
    fourthRow->addWidget(display);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    mainLayout->addLayout(fourthRow);


    setLayout(mainLayout);
    setWindowTitle("Software Review");
    setFixedHeight(sizeHint().height());
    resize(300, height());
}



void SoftwareReviewDialog::addSoftware()
{
    QString text = lineEdit->text();
    if (recommended->isChecked() && !text.isEmpty())
    {
        hash->insert(text,dateEdit->text());
        lineEdit->clear();
        lineEdit->setPlaceholderText("Enter Software");
        dateEdit->setDate(QDate::currentDate());
        recommended->setChecked(false);
    }
    else if (text.isEmpty())
    {
        QMessageBox::information(this,"No Software", "Enter the name of a software \n Check the box ");
    }
    else
    {
        QMessageBox::warning(this,"THE BOXXXX!", "Ensure the box is checked");
    }

}

void SoftwareReviewDialog::displayList()
{
    if (hash->isEmpty())
    {
        QMessageBox::warning(this,"No Software added", "Add a software via the interface");
        return;
    }
    QHash<QString,QString>::iterator i;
    for (i=hash->begin();i != hash->end(); ++i)
    {
        qDebug() << QString("%1 %2 %3").arg(i.key()).arg(" ").arg(i.value());
    }

}


SoftwareReviewDialog::~SoftwareReviewDialog()
{
    delete hash;
}





















