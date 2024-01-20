#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTranslator>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // This should be called before accessing any UI elements

    // Create a QTranslator object
    QTranslator translator;
    // Load the Dutch translation file (e.g., "translatorStage1_nl.qm" for Dutch)
    if(translator.load("C:/Users/ashis/OneDrive/Desktop/Qt/Final Projects/translatorStage1/translatorStage1_nl.qm")) {
        // Install the translator into the application
        qApp->installTranslator(&translator);
    } else {
        // Handle the error if the file is not loaded
        qDebug() << "Could not load translation file.";
    }

    // Use tr() to mark the string for translation
    QString helloWorld = tr("Hello World");
    // Set the translated text to the textBrowser
    ui->textBrowser->setText(helloWorld);
}

MainWindow::~MainWindow()
{
    delete ui;
}
