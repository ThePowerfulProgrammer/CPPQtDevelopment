#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>

namespace Ui {
class thirdDialog;
}

class thirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit thirdDialog(QWidget *parent = 0);
    ~thirdDialog();

private:
    Ui::thirdDialog *ui;
};

#endif // THIRDDIALOG_H
