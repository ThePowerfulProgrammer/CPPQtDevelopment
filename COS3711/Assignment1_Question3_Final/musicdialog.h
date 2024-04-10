#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H
#include <QDialog>

class QStandardItemModel;
class QTableView;
class QString;
class QLabel;
class QSpinBox;
class QDoubleSpinBox;
class QPushButton;
class QLineEdit;



class MusicDialog : public QDialog
{

    Q_OBJECT

public:
    MusicDialog(QWidget *parent = 0);
    ~MusicDialog();

public slots:
    void addDate();
    void deleteDate();

private:
  // 1st row
    QLabel *composerLabel;
    QLabel *albumTitleLabel;
    QLabel *replacementCostLabel;
    QLabel *ratingLabel;

    // 2nd row
    QLineEdit *addComposer;
    QLineEdit *addAlbum;
    QDoubleSpinBox *addReplacement;
    QSpinBox *addRating;
    QPushButton *addButton;

    // 3rd row
    QStandardItemModel *model;
    QTableView *tableView;

   // 4th row
   QPushButton *deleteButton;

};

#endif // MUSICDIALOG_H
