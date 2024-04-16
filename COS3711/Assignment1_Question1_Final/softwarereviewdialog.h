#ifndef SOFTWAREREVIEWDIALOG_H
#define SOFTWAREREVIEWDIALOG_H

#include <QDialog>
#include <QMultiHash>
// foward declarations
class QCheckBox;
class QLineEdit;
class QLabel;
class QPushButton;
class QDateEdit;


class SoftwareReviewDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SoftwareReviewDialog(QWidget *parent = 0);
    ~SoftwareReviewDialog();

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
    QCheckBox *recommend;
    QMultiHash<QString,QString> *hash;

};

#endif // SOFTWAREREVIEWDIALOG_H
