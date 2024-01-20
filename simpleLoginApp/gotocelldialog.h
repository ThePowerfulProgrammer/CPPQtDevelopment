#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H
#include <QDialog>


class gotocelldialog : public QDialog, public Ui::GoToCellDialog
{
    Q_OBJECT
public:
    gotocelldialog(QWidget * parent=0);

private slots:
    void on_lineEdit_textChanged();


};

#endif // GOTOCELLDIALOG_H

