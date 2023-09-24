#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);

    // The main window needs some more private slots and several private functions
    // to support the user interface

private slots:
/*
Some menu options, like File|New and Help|About, are implemented as private
slots in MainWindow. Most slots have void as their return value, but save() and
saveAs() return a bool. The return value is ignored when a slot is executed in
response to a signal, but when we call a slot as a function the return value is
available to us just as it is when we call any ordinary C++ function

*/
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();
};

#endif // MAINWINDOW_H
