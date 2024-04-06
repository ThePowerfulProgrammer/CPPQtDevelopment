#include "softwarereviewdialog.h"
#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QDate>
#include <QDateEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QDebug>
#include <QList>
#include <QMessageBox>

SoftwareReviewDialog::SoftwareReviewDialog(QWidget *parent)
    : QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint), hash(new QMultiHash<QString,QString>)
{
    // 1) set up my widgets
    lineEdit = new QLineEdit;
    lineEdit->setPlaceholderText("Enter Software");
    lineEdit->setProperty("mandatoryField", true);
    nameLabel = new QLabel("Name");
    nameLabel->setBuddy(lineEdit);

    dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setCalendarPopup(true);
    dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));
    dateEdit->setMaximumDate(QDate::currentDate().addDays(365));
    dateEdit->setDisplayFormat("dd.MM.yyyy");
    dateLabel = new QLabel("Date");
    dateLabel->setBuddy(dateEdit);

    recommended = new QCheckBox("Recommend");

    add = new QPushButton("Add");
    add->setObjectName("add");
    display = new QPushButton("Display");
    display->setObjectName("display");


    // signals and slots
    connect(add, SIGNAL(clicked()), this, SLOT(addSoftware()));
    connect(display,SIGNAL(clicked()), this, SLOT(displayList()));


    // Create the layouts
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

    // set main layout
    setLayout(mainLayout);
    setWindowTitle("Software Review");
    setFixedHeight(sizeHint().height());
    resize(300,height());


}

void SoftwareReviewDialog::addSoftware()
{
    QString text = lineEdit->text();
    if (!text.isEmpty())
    {
        QString recommendation = recommended->isChecked() ? "Yes" : "No";
        QString key = text + "," + recommendation;
        hash->insert(key, dateEdit->text());
        lineEdit->clear();
        lineEdit->setPlaceholderText("Enter Software");
        dateEdit->setDate(QDate::currentDate());
        recommended->setChecked(false);
    }
    else
    {
        QMessageBox::information(this,"No Software Text","1) Enter the name of a software in the appropriately labelled box \n2) Check the box");
    }
}

void SoftwareReviewDialog::displayList()
{
    if (hash->isEmpty())
    {
        QMessageBox::warning(this,"No Software added", "Add a software using the interface");
        return;
    }
    const int columnWidth = 12;
    qDebug() << QString("%1 %2 %3").arg("Software", columnWidth).arg("Date of Review", columnWidth).arg("Recommended");
    QHash<QString,QString>::iterator i;
    for (i=hash->begin();i != hash->end(); ++i)
    {
        QStringList keyParts = i.key().split(",");
        QString software = keyParts[0];
        QString recommendation = keyParts[1];
        qDebug() << QString("%1 %2   %3").arg(software, columnWidth).arg(i.value(), columnWidth).arg(recommendation);
    }
    qDebug() << "\n" << "\n" << "\n" ;
}



SoftwareReviewDialog::~SoftwareReviewDialog()
{
    delete hash;
}


