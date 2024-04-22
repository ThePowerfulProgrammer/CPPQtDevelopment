#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

class QPushButton;
class QTextEdit;
class QTextDocument;
class QTextCursor;

class searchDialog : public QDialog
{
    Q_OBJECT
public:
    explicit searchDialog(QWidget *parent = 0);

signals:

public slots:
    void loadDate(); // load in a text file for processing
    void processData(); // process (search file for Regex match)

private:
    QPushButton *loadBtn;
    QPushButton *processBtn;
    QTextEdit *textEdit;
    QTextDocument *document;
    QTextCursor *cursor;
};

#endif // SEARCHDIALOG_H
