#include "thirddialog.h"
#include "ui_thirddialog.h"

thirdDialog::thirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdDialog)
{
    ui->setupUi(this);
}

thirdDialog::~thirdDialog()
{
    delete ui;
}
