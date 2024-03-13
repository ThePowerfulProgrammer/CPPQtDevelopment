#include <QApplication>
#include <QListView>
#include <QStringListModel>
#include <QSplitter>
#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>
#include <QModelIndex>
#include <QDebug>
#include <QTableView>
#include <QStandardItemModel>

void createModel()
{
    QStandardItemModel *model = new QStandardItemModel(2,2);
    QStringList list;
    list << "Col 1" << "Col 2";
    model->setHorizontalHeaderLabels(list);

    for (int row=0;row<model->rowCount(); ++row)
    {
        for (int column = 0;column<model->columnCount();++column)
        {
            QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
            model->setItem(row, column, item);
        }
    }

    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    QSplitter *splitter = new QSplitter;

//    QFileSystemModel *model = new QFileSystemModel;
//    model->setRootPath(QDir::currentPath());



//    QTreeView *tree = new QTreeView(splitter);
//    tree->setModel(model);
//    tree->setRootIndex(model->index(QDir::currentPath()));

//    QListView *list = new QListView(splitter);
//    list->setModel(model);
//    list->setRootIndex(model->index(QDir::currentPath()));




//    splitter->setWindowTitle("Two views onto the same file system model");
//    splitter->show();

    createModel();

    return a.exec();

}
