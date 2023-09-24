#ifndef DIALOG_H
#define DIALOG_H
#include <QStringList>
#include <QDialog>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0, int timeInterval = 5000);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int currentImageIndex;
    QTimer *imageTimer;
    QStringList imagePaths;
    int timeChange;

private slots:
    void rotateImages();

};

#endif // DIALOG_H
