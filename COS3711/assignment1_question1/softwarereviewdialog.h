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

// action functions
//signals:
//    void emitMessage(QString txt);


// reaction functions Connect a slot to emit a signal
private slots:
    void addSoftware();
    void displayList();
    void ondateChanged();




private:
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QPushButton *add;
    QPushButton *display;
    QCheckBox *recommended;
    QMultiHash<QString, QString> *hash;
};

#endif // SOFTWAREREVIEWDIALOG_H
