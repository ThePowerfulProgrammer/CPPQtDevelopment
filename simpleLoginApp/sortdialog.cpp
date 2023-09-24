#include <QtGui>
#include "sortdialog.h"
#include "ui_sortdialog.h"

// ctor, Everything that happenns when we create the object
sortDialog::sortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortDialog)
{
    ui->setupUi(this);
    // hides sec and tert parts of the dialog --> This is how we do the cool trick --> It still exists
    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();
    // prevent user from resizing dialog, dialog automatically resizes
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    // init contents of comboboxes based on the selected columns in the spreadsheet
    setColumnRange('A','Z');
}


// Definition of function declared in class header file
void sortDialog::setColumnRange(QChar first, QChar last)
{
    ui->primaryColumnCombo->clear();
    ui->secondaryColumnCombo->clear();
    ui->tertiaryColumnCombo->clear();

    ui->secondaryColumnCombo->addItem(tr("None"));
    ui->tertiaryColumnCombo->addItem(tr("None"));

    // return a widget's ideal size, which the layout tries to honour
    ui->primaryColumnCombo->setMinimumSize(ui->secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while (ch <= last)
    {
        ui->primaryColumnCombo->addItem(QString(ch));
        ui->secondaryColumnCombo->addItem(QString(ch));
        ui->tertiaryColumnCombo->addItem(QString(ch));
        ch = ch.unicode()+1;
    }

}

sortDialog::~sortDialog()
{
    delete ui;
}
