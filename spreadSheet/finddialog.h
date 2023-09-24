#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
// Created using code

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

namespace Ui {
class findDialog;
}

class findDialog : public QDialog
{
    Q_OBJECT
    //The Q_OBJECT macro at the beginning of the class definition is necessary for all
    //classes that define signals or slots

public:
    explicit findDialog(QWidget *parent = 0);
//    The parent parameter specifies the parent widget.
//    The default is a null pointer, meaning that the
//    dialog has no parent.


    ~findDialog();
signals:
    void findNext(const QString& str, Qt::CaseSensitivity cs);
    void findPrevious(const QString& str, Qt::CaseSensitivity cs);
//    The signals section declares two signals that the dialog emits when the user
//    clicks the Find button. If the Search backward option is enabled, the dialog emits
//    findPrevious(); otherwise, it emits findNext().

private slots:
    void findClicked();
    void enableFindButton(const QString& text);

private:
    Ui::findDialog *ui;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

//In the class’s private section, we declare two slots. To implement the slots, we
//will need to access most of the dialog’s child widgets, so we keep pointers to
//them as well. The slots keyword is, like signals, a macro that expands into a
//construct that the C++ compiler can digest.
//For the private variables, we used forward declarations of their classes. This
//was possible because they are all pointers and we don’t access them in the
//header file, so the compiler doesn’t need the full class definitions.

#endif // FINDDIALOG_H
