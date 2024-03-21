#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QDialog>
#include <QTableView>
#include <QStandardItemModel>
#include <QString>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QModelIndex>
#include "delegate.h"

class myDialog : public QDialog
{
    Q_OBJECT // allow the GUI to access signal and slot functionality
public:
    myDialog(QWidget *parent = 0);
    ~myDialog();


public slots:
    void addData();
    void deleteData();
    void output(QModelIndex index);
private:
    // 1st row: 4 labels
    QLabel *composerLabel;
    QLabel *albumTitle;
    QLabel *replacementCost;
    QLabel *rating;

    // 2nd row: 4 input widgets but these will have to be delegates and 1 button
    QLineEdit *addComposer;
    QLineEdit *addAlbum;
    QDoubleSpinBox *addReplacement;
    QSpinBox *addRating;
    QPushButton *add;

    // 3rd row
    QStandardItemModel *model;
    QTableView *tableView;

    // 4th row
    QPushButton *deleteButton;

};

#endif // MYDIALOG_H
