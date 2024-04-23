#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

// fwd declarations
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
    void loadData();
    void processData();

private:
    QPushButton *loadBtn;
    QPushButton *processBtn;
    QTextEdit *textEdit;
    QTextDocument *document;
    QTextCursor *cursor;
};

#endif // SEARCHDIALOG_H
