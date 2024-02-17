#include "softwarereviewdialog.h"
#include <QDate>

//QLabel *nameLabel;
//QLabel *dateLabel;
//QLineEdit *lineEdit;
//QDateEdit *dateEdit;
//QPushButton *add;
//QPushButton *display;
//QCheckBox *recommended;


SoftwareReviewDialog::SoftwareReviewDialog(QWidget *parent): QDialog(parent)
{
    // set up widgets
    lineEdit = new QLineEdit("Software");
    nameLabel = new QLabel("Name");

    dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));
    dateEdit->setMaximumDate(QDate::currentDate().addDays(365));
    dateEdit->setDisplayFormat("yyyy.MM.dd");
    dateLabel = new QLabel("Date");

    recommended = new QCheckBox("Recommend");

    add = new QPushButton("Add");
    display = new QPushButton("Display");

}
