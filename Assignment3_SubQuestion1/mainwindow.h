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
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\item.h"
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\itemreader.h"
#include "C:\Users\ashis\OneDrive\Desktop\Item_reader_writer\Item_reader_writer\itemwriter.h"



class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


public slots:
    void openDialog();
    void onAddItem();
    void saveFile();
    void exitApplication();
    void onchangeItem();
    void removeFunction();

private:
    QToolBar *toolbar;
    QMenu *fileMenu;
    bool dataChanged;


};

#endif // MAINWINDOW_H
