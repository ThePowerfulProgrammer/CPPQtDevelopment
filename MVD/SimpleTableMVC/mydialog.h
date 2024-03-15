#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QDialog>
#include <QTableView>
#include <QStandardItemModel>


class myDialog : public QDialog
{
    Q_OBJECT // allow the GUI to access signal and slot functionality
public:
    myDialog(QWidget *parent = 0);
    ~myDialog();


public slots:
    void output();
private:
    QStandardItemModel *model;
    QTableView *tableView;
};

#endif // MYDIALOG_H
