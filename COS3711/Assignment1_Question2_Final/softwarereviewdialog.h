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
//    Q_PROPERTY(QString name )
//    Q_PROPERTY(QDate date )
//    Q_PROPERTY(bool recommended )
public:
    explicit SoftwareReviewDialog(QWidget *parent = 0);
    ~SoftwareReviewDialog();

//    QString getName() const;
//    QDate getDate() const;

//    bool isRecommended() const;

public slots:
    void addSoftwareReview();
    void displayList();
    void displayReflection();

private:
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QPushButton *add;
    QPushButton *display;
    QPushButton *m_displayReflection;
    QCheckBox *recommend;
    QMultiHash<QString,QString> *hash;

};

#endif // SOFTWAREREVIEWDIALOG_H
