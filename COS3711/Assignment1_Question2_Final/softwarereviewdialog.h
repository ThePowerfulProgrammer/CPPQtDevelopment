#ifndef SOFTWAREREVIEWDIALOG_H
#define SOFTWAREREVIEWDIALOG_H

#include <QDialog>
#include "softwarereview.h"

class QCheckBox;
class QLineEdit;
class QLabel;
class QPushButton;
class QDateEdit;
class QList<SoftwareReview>;

class SoftwareReviewDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SoftwareReviewDialog(QWidget *parent = 0);

signals:

public slots:
    void addSoftwareReview();
    void displayList();


private:
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QPushButton *add;
    QPushButton *display;
    QPushButton *displayReviewBtn;
    QCheckBox *recommend;
    QList<SoftwareReview*> reviews;
};

#endif // SOFTWAREREVIEWDIALOG_H
