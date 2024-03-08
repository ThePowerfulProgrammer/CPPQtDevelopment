#include <QApplication>
#include <QStringListModel>
#include <QStringList>
#include <QTableView>
#include <QDialog>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDialog *dialog = new QDialog();
    QPushButton *add = new QPushButton("add");

    QStringList list;
    list << "Cats" << "dogs" << "puppies" << "kittens";

    QStringListModel *model = new QStringListModel;
    model->setStringList(list);

    QTableView *view = new QTableView;
    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(view);
    verticalLayout->addSpacing(10);
    verticalLayout->addWidget(add);

    dialog->setLayout(verticalLayout);

    dialog->show();

    return a.exec();
}
