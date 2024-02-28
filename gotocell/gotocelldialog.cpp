#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"


//In the constructor, we call setupUi() to initialize the form. Thanks to multiple
//inheritance, we can access Ui::GoToCellDialog’s members directly. After creating the user interface, setupUi() will also automatically connect any slots that
//follow the naming convention on_objectName_signalName() to the corresponding
//objectName’s signalName() signal. In our example, this means that setupUi() will
//establish the following signal–slot connection:
//connect(lineEdit, SIGNAL(textChanged(const QString &)),
//this, SLOT(on_lineEdit_textChanged()));

//Also in the constructor, we set up a validator to restrict the range of the input.
//Qt provides three built-in validator classes: QIntValidator, QDoubleValidator,
//and QRegExpValidator. Here we use a QRegExpValidator with the regular expression “[A-Za-z][1-9][0-9]{0,2}”, which means: Allow one uppercase or lowercase
//letter, followed by one digit in the range 1 to 9, followed by zero, one, or two
//digits each in the range 0 to 9.

GoToCellDialog::GoToCellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

//The on_lineEdit_textChanged() slot enables or disables the OK button,according
//to whether the line edit contains a valid cell location. QLineEdit::hasAcceptableInput() uses the validator we set in the constructor

/** Thanks bing */
//The on_lineEdit_textChanged() function is a slot that gets called whenever the text in the lineEdit widget changes. This is a feature of Qt’s signal-slot mechanism, and the naming convention on_<objectName>_<signalName> is used for automatically connecting signals to slots.

//Here’s how it works in your code:

//When the text in lineEdit changes (for example, when the user types something), the textChanged() signal is emitted.
//Because of the naming convention, this signal is automatically connected to the on_lineEdit_textChanged() slot, so that function is called.
//Inside the on_lineEdit_textChanged() function, ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput()); is called. This line enables the okButton if the text in lineEdit is acceptable according to its validator, and disables it otherwise.
//The validator was set in the constructor with ui->lineEdit->setValidator(new QRegExpValidator(regExp,this));, where regExp is a regular expression that matches a letter followed by 1 to 3 digits. So, the okButton will be enabled only when the text in lineEdit matches this pattern.

void GoToCellDialog::on_lineEdit_textChanged()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

