#include <QApplication>
#include <QListView>
#include <QStringListModel>
#include <QSplitter>
#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>
#include <QModelIndex>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QSplitter *splitter = new QSplitter;

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());


    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));




    splitter->setWindowTitle("Two views onto the same file system model");
    splitter->show();
    return a.exec();

}
