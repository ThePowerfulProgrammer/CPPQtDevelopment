#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QMenu>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QLabel>
#include "itemdialog.h"
#include "itemlist.h"
#include "item.h"
#include "itemreader.h"
#include "itemwriter.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);

public slots:
    void openDialog();
    void onAddItem();
    void saveFile();
    void exitApplication();
    void onChangeItem();
    void removeFunction();

private:
    QToolBar *toolbar;
    QMenu *fileMenu;
    bool dataChanged;


};

#endif // MAINWINDOW_H
