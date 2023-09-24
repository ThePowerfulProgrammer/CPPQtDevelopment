#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

namespace Ui {
class notePad;
}

class notePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit notePad(QWidget *parent = 0);
    ~notePad();

private slots:
    void on_quitButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::notePad *ui;
};

#endif // NOTEPAD_H
