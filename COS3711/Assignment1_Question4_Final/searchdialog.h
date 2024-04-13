#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

class QPushButton;
class QTextEdit;

class SearchDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SearchDialog(QWidget *parent = 0);

signals:

public slots:
    void loadData(); // simply load in a txt file and display contents in textEdit
//    void processData(); // process (match content to REGEXP match) and display in textEdit


private:
    QPushButton *loadBtn;
    QPushButton *processBtn;
    QTextEdit *textEdit;


};

#endif // SEARCHDIALOG_H
