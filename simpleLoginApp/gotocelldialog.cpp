#include <QtGui>
#include "gotocelldialog.h"

gotocelldialog::gotocelldialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator
}






#include <QtGui>
#include "gotocelldialog.h"
GoToCellDialog::GoToCellDialog(QWidget *parent)
 : QDialog(parent)
{
 setupUi(this);
 QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
 lineEdit->setValidator(new QRegExpValidator(regExp, this));
 connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
 connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}
