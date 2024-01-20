#include "exercisedialog.h"
#include <QFormLayout>
#include <QPushButton>



exerciseDialog::exerciseDialog(QWidget *parent): QDialog(parent)
{
    // init all members
    name = new QLineEdit(this);

    description = new QLineEdit(this);

    RPE = new QSpinBox(this);
    RPE->setValue(0);
    RPE->setMaximum(10);

    sets = new QSpinBox(this);
    sets->setValue(0);
    sets->setMaximum(10);

    reps = new QSpinBox(this);
    reps->setValue(0);
    reps->setMaximum(101);

    max = new QDoubleSpinBox(this);
    max->setValue(0);
    max->setSingleStep(0.5);
    max->setMaximum(1000);

    workingWeight = new QDoubleSpinBox(this);
    workingWeight->setValue(0);
    workingWeight->setSingleStep(0.5);
    workingWeight->setMaximum(1000);

    rest = new QSpinBox(this);
    rest->setValue(0);
    rest->setMaximum(1000);


    // Create layout
    QFormLayout *layout = new QFormLayout(this);

    layout->addRow("Name: ", name);
    layout->addRow("Desc: ", description);
    layout->addRow("RPE: ", RPE);
    layout->addRow("Sets: ", sets);
    layout->addRow("Reps: ", reps);
    layout->addRow("Max: ", max);
    layout->addRow("workingWeight: ", workingWeight);
    layout->addRow("Rest: ", rest);

    QPushButton *okButton =  new QPushButton(this);
    okButton->setStyleSheet("QPushButton {border-color: blue; font-size: 15px;} ");
    okButton->setText("OK");
    QPushButton *cancelButton =  new QPushButton(this);
    cancelButton->setText("Cancel");

    // use built in signals and slots
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::accept);

    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    setLayout(layout);
    setFixedSize(600,400);
}

exercise* exerciseDialog::addExercise()
{
    exerciseDialog* dialog = new exerciseDialog;
    QFont font("Times new Roman",12);
    dialog->setFont(font);
    dialog->setWindowTitle("Add Exercise :)");
    if (dialog->exec() == QDialog::Accepted)
    {
        return new exercise(dialog->name->text(),dialog->description->text(), dialog->sets->value(), dialog->reps->value(),dialog->RPE->value(),dialog->workingWeight->value(),dialog->rest->value(), dialog->max->value());
    }
    return 0;
}

exercise* exerciseDialog::changeExercise(exercise *ex)
{
    if (ex == 0)
    {
        return 0;
    }
    exerciseDialog dialog;
    QFont font("Times new Roman",12);
    dialog.setFont(font);
    dialog.setWindowTitle("Alter exercise");
    dialog.name->setText(ex->getName());
    dialog.description->setText(ex->getDescription());
    dialog.RPE->setValue(ex->getRPE());
    dialog.sets->setValue(ex->getSets());
    dialog.reps->setValue(ex->getReps());
    dialog.max->setValue(ex->getMax());
    dialog.workingWeight->setValue(ex->getWorkingWeight());
    dialog.rest->setValue(ex->getRest());

    if (dialog.exec() == QDialog::Accepted)
    {
        exercise *newExercise =  new exercise(dialog.name->text(),dialog.description->text(), dialog.sets->value(), dialog.reps->value(),dialog.RPE->value(),dialog.workingWeight->value(),dialog.rest->value(), dialog.max->value());
        newExercise->setID(newExercise->getId()-1);
        return newExercise;
    }
    return 0;

}
