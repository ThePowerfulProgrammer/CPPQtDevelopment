#ifndef SOFTWAREREVIEWDIALOG_H
#define SOFTWAREREVIEWDIALOG_H

#include <QDialog> // required
#include <QMultiHash>

// forward declarations
class QCheckBox;
class QLineEdit;
class QLabel;
class QPushButton;
class QDateEdit;



class SoftwareReviewDialog : public QDialog
{
    Q_OBJECT // allow the GUI to access signal and slot functionality

public:
    SoftwareReviewDialog(QWidget *parent = 0);
    ~SoftwareReviewDialog();

private slots:
    void addSoftware();
    void displayList();
    void displayListReflective();

private:
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QPushButton *add;
    QPushButton *display;
    QPushButton *reflectiveDisplay;
    QCheckBox *recommended;
    QMultiHash<QString, QString> *hash;
};

#endif // SOFTWAREREVIEWDIALOG_H
