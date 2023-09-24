#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

namespace Ui {
class GoToCellDialog;
}

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget *parent = 0);
    ~GoToCellDialog();

private:
    Ui::GoToCellDialog *ui;

private slots:
    void on_lineEdit_textChanged();
};

#endif // GOTOCELLDIALOG_H
