#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QSpinBox>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canvas = new Canvas(this);
    setCentralWidget(canvas);

    // Main Window
    QLabel  *penWidthLabel = new QLabel("Draw Width", this);
    QSpinBox *penWidthSpinBox = new QSpinBox(this);
    penWidthSpinBox->setMinimum(1);
    penWidthSpinBox->setMaximum(15);


    QLabel *fillClrLabel = new QLabel("Fill Color", this);
    fillClrBtn = new QPushButton(this);

    QLabel *penClrLabel = new QLabel("Pen Colour", this);
    penClrBtn = new QPushButton(this);

    fillCheckBox = new QCheckBox("Fill Shape", this);

    // Tool bar
    QPushButton *rectBtn = new QPushButton(this);
    rectBtn->setIcon(QIcon(":/images/Rectangle.png"));

    QPushButton *penBtn = new QPushButton(this);
    penBtn->setIcon(QIcon(":/images/Pen.png"));

    QPushButton *ellipseBtn = new QPushButton(this);
    ellipseBtn->setIcon(QIcon(":/images/Circle.png"));


    QPushButton *eraserBtn = new QPushButton(this);
    eraserBtn->setIcon(QIcon(":/images/Craser.png"));

    // My Own
    QPushButton *triangleBtn = new QPushButton(this);
    triangleBtn->setIcon(QIcon(":/images/Triangle.png"));

    // S && S
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(penWidthChange(int)));
    connect(penClrBtn, SIGNAL(clicked()), this, SLOT(changePenColor()));
    connect(fillClrBtn, SIGNAL(clicked()), this, SLOT(changeFillColor()));
    connect(fillCheckBox, SIGNAL(clicked()), this, SLOT(changeFillProperty()));


    ui->mainToolBar->addWidget(penWidthLabel);
    ui->mainToolBar->addWidget(penWidthSpinBox);
    ui->mainToolBar->addWidget(penClrLabel);
    ui->mainToolBar->addWidget(penClrBtn);
    ui->mainToolBar->addWidget(fillClrLabel);
    ui->mainToolBar->addWidget(fillClrBtn);
    ui->mainToolBar->addWidget(fillCheckBox);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(penBtn);
    ui->mainToolBar->addWidget(rectBtn);
    ui->mainToolBar->addWidget(ellipseBtn);
    ui->mainToolBar->addWidget(eraserBtn);
    ui->mainToolBar->addWidget(triangleBtn);

    setWindowTitle("Powerful Painter");
}

void MainWindow::penWidthChange(int width)
{

}

void MainWindow::changePenColor()
{

}

void MainWindow::changeFillColor()
{

}

void MainWindow::changeFillProperty()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
