#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QTextEdit>
#include <QDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),dataChanged(false)
{
    setWindowTitle("Workout Creator");

    resize(1000,800);

    toolbar = new QToolBar(this);
    addToolBar(toolbar);

    QAction *open = new QAction(tr("&O"), this);
    QAction *save = new QAction(tr("&S"), this);
    QAction *exit = new QAction(tr("&X"), this);
    QAction *add = new QAction(tr("&A"),this);
    QAction *change = new QAction(tr("&C"),this);
    QAction *remove = new QAction(tr("&R"),this);


    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(exit);
    toolbar->addSeparator();
    toolbar->addSeparator();

    connect(open,&QAction::triggered, this,&MainWindow::openDialog);
    connect(save,&QAction::triggered,this,&MainWindow::saveFile);
    connect(exit,&QAction::triggered,this,&MainWindow::exitApplication);

    toolbar->setStyleSheet(
                "QToolBar {"
                "border: 1px solid red;"
                "background-color:  #e6e6e6;"
                "}"
                "QToolButton {"
                "color: black;"
                "background-color: #f2f2f2;"
                "font-size: 25px; "
                "font-family: Times new roman;"
                "border: 2px solid black;"
                "}"
                "QToolButton:hover {"
                "color:  #80002a;"
                "}"
                );

   toolbar->addAction(add);
   toolbar->addSeparator();
   toolbar->addAction(change);
   toolbar->addSeparator();
   toolbar->addAction(remove);


   connect(add,&QAction::triggered,this,&MainWindow::onAddExercise);
   connect(change,&QAction::triggered,this,&MainWindow::onchangeExercise);
   connect(remove,&QAction::triggered,this,&MainWindow::removeExercise);

   fileMenu =  menuBar()->addMenu(tr("&File"));

   fileMenu->addAction(open);
   fileMenu->addAction(save);
   fileMenu->addSeparator();
   fileMenu->addAction(exit);

   fileMenu = menuBar()->addMenu(tr("Edit"));
}

void MainWindow::openDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open txt file"),"",
                                                            tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this,tr("Unable to open file"), file.errorString());
            return;
        }
        QTextStream in(&file);

        QTextEdit *textEdit = new QTextEdit(this);

        QString data = QString("%1\t%2\t%3\t%4\t%5\t%6\t%7\t%8\t%9\n")
            .arg("name", -10)
            .arg("description", -20)
            .arg("sets", -5)
            .arg("reps", -5)
            .arg("RPE", -5)
            .arg("WW", -15)
            .arg("rest", -2)
            .arg("max", -2)
            .arg("id", -2);
        data += in.readAll();

        toolbar->setStyleSheet(
                    "QToolBar {"
                    "border: 1px solid red;"
                    "background-color:  #e6e6e6;"
                    "}"
                    "QToolButton {"
                    "color: black;"
                    "background-color: #f2f2f2;"
                    "font-size: 25px; "
                    "font-family: Times new roman;"
                    "border: 2px solid black;"
                    "}"
                    "QToolButton:hover {"
                    "color:  #80002a;"
                    "}"
                    );

        textEdit->setText(data);
        textEdit->setReadOnly(true);
        textEdit->setStyleSheet(
                    "font-family:Times new roman;"
                    );
        qDebug() << textEdit->style() << '\n';
        qDebug() << textEdit->styleSheet() << '\n';
        setCentralWidget(textEdit);
    }
}

void MainWindow::onAddExercise()
{
    exercise *ex = exerciseDialog::addExercise();
    exerciseList list;

    if (ex != 0)
    {
        exercise newEx = *ex;
        list.append(newEx);
        qDebug() << list.getListOfExercises().size() << '\n';
        dataChanged = !dataChanged;
    }
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open txt file"),"",
                                                            tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        exerciseList list;
        qDebug() << list.getListOfExercises().size();
        list.exerciseListToTxt(fileName);
        list.getListOfExercises().clear();
        dataChanged = !dataChanged;
    }
}

void MainWindow::exitApplication()
{
    if (dataChanged == true)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Unsaved Changes", "Do you want to save the changes before exiting?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
        {
            saveFile();
        }
        else if (reply == QMessageBox::Cancel)
        {
            return;
        }
    }
    close();
}

void MainWindow::onchangeExercise()
{
    bool ok;

    int id = QInputDialog::getInt(this,tr("QInputDialog::getInt()"),tr("ID:"),1,1,10000,1,&ok);

    exerciseList list;
    if (ok)
    {
        exercise currentExercise = list.getListOfExercises()[id];
        exercise *ptrCurrentExercise = &currentExercise;

        if (ptrCurrentExercise != 0)
        {

            ptrCurrentExercise = exerciseDialog::changeExercise(ptrCurrentExercise);

            if (ptrCurrentExercise)
            {
                dataChanged = true;
            }
        }
        else
        {
            QMessageBox::information(this,"Exercise not found","No exercise found with ID.");
        }
    }
}

void MainWindow::removeExercise()
{
    bool ok;

    int id = QInputDialog::getInt(this,tr("QInputDialog::getInt()"),tr("ID:"),0,0,10000,1,&ok);
    if (ok)
    {
        exerciseList list;
        if(list.getListOfExercises().contains(id))
        {
            exercise exToRemove = list.getListOfExercises()[id];
            exercise* ptrExToRemove = &exToRemove;

            QMessageBox::StandardButton confirmDelete;
            confirmDelete = QMessageBox::question(this,"Confirm Delete", "Confirm delete ",QMessageBox::Yes | QMessageBox::No);
            if (confirmDelete == QMessageBox::Yes)
            {
                list.removeExercise(ptrExToRemove);
                dataChanged = true;
            }
            else
            {
                QMessageBox::information(this,"Delete Denied","User cancelled delete");
            }
        }
        else
        {
            QMessageBox::warning(this,"Exercise Absent", "No Ex with associated id");
        }

    }
}
