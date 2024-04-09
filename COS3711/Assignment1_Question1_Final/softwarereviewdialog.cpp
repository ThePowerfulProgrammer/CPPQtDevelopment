#include "softwarereviewdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QDate>
#include <QPushButton>
#include <QMessageBox>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>

SoftwareReviewDialog::SoftwareReviewDialog(QWidget *parent) :
    QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint), hash(new QMultiHash<QString, QString>)
{

    // 1) Set up my widgets
    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Enter Software name");
    lineEdit->setProperty("mandatoryField",true);
    nameLabel = new QLabel("Name",this);
    nameLabel->setBuddy(lineEdit);

    dateEdit = new QDateEdit(QDate::currentDate(),this);
    dateEdit->setCalendarPopup(true);
    dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));
    dateEdit->setMaximumDate(QDate::currentDate().addDays(365)); // Max 1 year before or after
    dateEdit->setDisplayFormat("dd.MM.yyyy");
    dateLabel = new QLabel("Date", this);
    dateLabel->setBuddy(dateEdit);

    recommened = new QCheckBox("Recommend", this);

    add = new QPushButton("Add",this);
    add->setObjectName("add");
    add->setDefault(true);
    display = new QPushButton("Display", this);
    display->setObjectName("Display");

    // signals and slots
    connect(add, SIGNAL(clicked()), this, SLOT(addSoftwareReview()));
    connect(display, SIGNAL(clicked()), this, SLOT(displayList()));

    // Create the layouts
    QHBoxLayout *firstRow = new QHBoxLayout;
    firstRow->addWidget(nameLabel);
    firstRow->addWidget(lineEdit);


    QHBoxLayout *secondRow = new QHBoxLayout;
    secondRow->addWidget(dateLabel);
    secondRow->addWidget(dateEdit);

    QHBoxLayout *thirdRow = new QHBoxLayout;
    thirdRow->addStretch();
    thirdRow->addWidget(recommened);

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

void SoftwareReviewDialog::addSoftwareReview()
{
    QString text = lineEdit->text();
    if (!text.isEmpty())
    {
        QString recommendation = recommened->isChecked() ? "Yes" : "No";
        QString key = text + "," + recommendation;
        hash->insert(key,dateEdit->text());
        lineEdit->clear();
        lineEdit->setPlaceholderText("Enter Software Name");
        dateEdit->setDate(QDate::currentDate());
        recommened->setChecked(false);
    }
    else
    {
        QMessageBox::information(this, "No Software Text", "1) Enter the name of a software in appropriate box");
    }
}


// No reflective programming here YET
void SoftwareReviewDialog::displayList()
{
    if (hash->isEmpty())
    {
        QMessageBox::warning(this, "No Software reviews added", "Add a Software using the interface");
        return;
    }
    const int columnWidth = 12;
    qDebug() << QString("%1 %2 %3").arg("Software",columnWidth).arg("Date Of Review",columnWidth).arg("Recommended");
    QHash<QString,QString>::iterator i;
    for (i = hash->begin();i!=hash->end();++i)
    {
        QStringList keyParts = i.key().split(",");
        QString software = keyParts[0];
        QString recommendation = keyParts[1];
        qDebug() << QString("%1 %2   %3").arg(software, columnWidth).arg(i.value(), columnWidth).arg(recommendation);
    }
    qDebug() << "\n" << "\n" << "\n";
}

SoftwareReviewDialog::~SoftwareReviewDialog()
{
    delete hash;
}


