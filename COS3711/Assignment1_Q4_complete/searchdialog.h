#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

class QPushButton;
class QTextEdit;
class QTextDocument;
class QTextCursor;


class SearchDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SearchDialog(QWidget *parent = 0);

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
