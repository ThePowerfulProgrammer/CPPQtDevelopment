#ifndef SOFTWAREREVIEWDIALOG_H
#define SOFTWAREREVIEWDIALOG_H
#include <QDialog>
#include <QMultiHash>

// FD
class QCheckBox;
class QLineEdit;
class QLabel;
class QPushButton;
class QDateEdit;




class SoftwareReviewDialog : public QDialog
{
    Q_OBJECT // allows our GUI to access signals and slot functionality

public:
    SoftwareReviewDialog(QWidget *parent = 0);
    ~SoftwareReviewDialog();

private slots:
    void addSoftware();
    void displayList();

private:
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QPushButton *add;
    QPushButton *display;
    QCheckBox *recommended;
    QMultiHash<QString,QString> *hash;

};

#endif // SOFTWAREREVIEWDIALOG_H
