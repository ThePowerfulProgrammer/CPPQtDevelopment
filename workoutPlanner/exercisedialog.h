#ifndef EXERCISEDIALOG_H
#define EXERCISEDIALOG_H

#include "exercise.h"
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

class exerciseDialog : public QDialog
{
public:
    exerciseDialog(QWidget *parent = 0);
    static exercise* addExercise(); // create an exercise object
    static exercise* changeExercise(exercise* ex); // modify an existing object
private:
    QLineEdit *name;
    QLineEdit *description;
    QSpinBox *RPE;
    QSpinBox *sets;
    QSpinBox *reps;
    QDoubleSpinBox *max;
    QDoubleSpinBox *workingWeight;
    QSpinBox *rest;
};

#endif // EXERCISEDIALOG_H
