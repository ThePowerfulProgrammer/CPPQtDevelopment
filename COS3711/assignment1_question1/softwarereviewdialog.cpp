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


//    if (parent->inherits("QDialog"))
//    {
//        qDebug() << "Call yoour mama: QDIalog" << "\n";
//    }

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
    reflectiveDisplay = new QPushButton("Display reflective");
    reflectiveDisplay->setObjectName("reflectiveDisplay");


    // signals and slots
    connect(add, SIGNAL(clicked()), this, SLOT(addSoftware()));
    connect(display,SIGNAL(clicked()), this, SLOT(displayList()));
    connect(reflectiveDisplay, SIGNAL(clicked()), this, SLOT(displayListReflective()));

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

    QHBoxLayout *fifthRow = new QHBoxLayout;
    fifthRow->addWidget(reflectiveDisplay);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    mainLayout->addLayout(fourthRow);
    mainLayout->addLayout(fifthRow);

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
    qDebug() << this->metaObject()->className() <<  this->metaObject()->methodCount() << "\n" << "\n" << "\n" ; // Using Reflection pattern
}

// works but not what I want
void SoftwareReviewDialog::displayListReflective()
{
    const QMetaObject *metaObject = this->metaObject();
    int count = metaObject->propertyCount(); // grab members from class
    for (int i = 0 ;i<count; ++i)
    {
        QMetaProperty metaProperty = metaObject->property(i);
        const char *name = metaProperty.name();
        QVariant value = this->property(name);
        qDebug() << QString("%1: %2").arg(name).arg(value.toString());
    }
}



SoftwareReviewDialog::~SoftwareReviewDialog()
{
    delete hash;
}


