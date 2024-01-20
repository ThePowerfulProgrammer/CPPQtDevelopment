#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QToolBar>
#include <QMenu>
#include <QVBoxLayout>
#include <QLabel>
#include "exercise.h"
#include "exercisedialog.h"
#include "exerciselist.h"
#include "exercisereader.h"
#include "exercisewriter.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void openDialog();
    void onAddExercise();
    void saveFile();
    void exitApplication();
    void onchangeExercise();
    void removeExercise();

private:
    QToolBar *toolbar;
    QMenu *fileMenu;
    bool dataChanged;
};

#endif // MAINWINDOW_H
