#ifndef SOFTWAREREVIEWDIALOG_H
#define SOFTWAREREVIEWDIALOG_H

#include <QDialog> // required
#include <QString>

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


// action functions Connect a slot to emit a signal
private slots:
    void sendMessage();

// reaction functions
signals:
    void emitMessage(QString txt);



private:
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QPushButton *add;
    QPushButton *display;
    QCheckBox *recommended;



};

#endif // SOFTWAREREVIEWDIALOG_H
