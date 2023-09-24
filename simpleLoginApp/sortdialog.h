#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

#include <ui_sortdialog.h>

namespace Ui {
class sortDialog;
}

class sortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sortDialog(QWidget *parent = 0);
    void setColumnRange(QChar first,QChar last);
    ~sortDialog();

private:
    Ui::sortDialog *ui;
};

#endif // SORTDIALOG_H
