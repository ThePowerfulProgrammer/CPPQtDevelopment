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
#include <QMetaProperty>

SoftwareReviewDialog::SoftwareReviewDialog(QWidget *parent) :
    QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint)
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

    recommend = new QCheckBox("Recommend", this);

    add = new QPushButton("Add",this);
    add->setObjectName("Add");
    add->setDefault(true);
    display = new QPushButton("Display", this);
    display->setObjectName("Display");
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
    thirdRow->addWidget(recommend);

    QHBoxLayout *fourthRow = new QHBoxLayout;
    fourthRow->addWidget(add);
    fourthRow->addWidget(display);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstRow);
    mainLayout->addLayout(secondRow);
    mainLayout->addLayout(thirdRow);
    mainLayout->addLayout(fourthRow);

    setLayout(mainLayout);
    setWindowTitle("Software Review Reflection pattern");
    setFixedHeight(sizeHint().height());
    resize(300, height());
}

void SoftwareReviewDialog::addSoftwareReview()
{
    QString text = lineEdit->text();
    if (!text.isEmpty())
    {
        SoftwareReview *review = new SoftwareReview(this);
        review->setSoftwareName(text);
        review->setReviewDate(dateEdit->date());
        review->setIsRecommended(recommend->isChecked());
        reviews.append(review);

        lineEdit->clear();
        lineEdit->setPlaceholderText("Enter Software Name");
        dateEdit->setDate(QDate::currentDate());
        recommend->setChecked(false);
    }
    else
    {
        QMessageBox::information(this, "No Software Text", "1) Enter the name of a software in appropriate box");
    }
}

void SoftwareReviewDialog::displayList()
{
    if (reviews.isEmpty())
    {
        QMessageBox::warning(this, "No Software reviews added", "Add a Software using the interface");
        return;
    }

    for (int i = 0; i < reviews.size(); ++i)
    {
        SoftwareReview *review = reviews.at(i);
        const QMetaObject *metaobject = review->metaObject();
        int count = metaobject->propertyCount();
        for (int j = 1; j < count; ++j)
        {
            QMetaProperty metaproperty = metaobject->property(j);
            const char *name = metaproperty.name();
            QVariant value = review->property(name);
            qDebug() << QString("%1: %2").arg(name).arg(value.toString());

        }
        qDebug() << "\n \n \n";
    }
}

