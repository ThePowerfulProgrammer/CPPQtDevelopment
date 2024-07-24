#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QSpinBox>
#include <QColorDialog>
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

    connect(rectBtn, SIGNAL(clicked()), this, SLOT(toolRect()));
    connect(ellipseBtn, SIGNAL(clicked()), this, SLOT(toolEllipse()));
    connect(penBtn, SIGNAL(clicked()), this, SLOT(toolPen()));
    connect(eraserBtn, SIGNAL(clicked()), this, SLOT(toolEraser()));

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

    QString css = QString("background-color: %1").arg(canvas->getPenColor().name());
    penClrBtn->setStyleSheet(css);

    css = QString("background-color: %1").arg(canvas->getFillColor().name());
    fillClrBtn->setStyleSheet(css);


    setWindowTitle("Powerful Painter");
}

void MainWindow::penWidthChange(int width)
{
    canvas->setPenWidth(width);
}

void MainWindow::changePenColor()
{
    QColor color = QColorDialog::getColor(canvas->getPenColor());
    if (color.isValid())
    {
        canvas->setPenColor(color);
        QString css = QString("background-color: %1").arg(color.name());
        penClrBtn->setStyleSheet(css);
    }
}

void MainWindow::changeFillColor()
{
    QColor color = QColorDialog::getColor(canvas->getPenColor());
    if(color.isValid()){
        canvas->setFillColor(color);
        QString css = QString("background-color : %1").arg(color.name());
        fillClrBtn->setStyleSheet(css);
    }
}

void MainWindow::changeFillProperty()
{
    canvas->setFill(fillCheckBox->isChecked());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toolRect()
{
    canvas->setTool(Canvas::Rectangle);
    statusBar()->showMessage("Tool: Rect");
}

void MainWindow::toolEllipse()
{
    canvas->setTool(Canvas::Ellipse);
    statusBar()->showMessage("Tool: Ellipse");
}

void MainWindow::toolPen()
{
    canvas->setTool(Canvas::Pen);
    statusBar()->showMessage("Tool: Pen");
}

void MainWindow::toolEraser()
{
    canvas->setTool(Canvas::Eraser);
    statusBar()->showMessage("Tool: Go Invisible");
}
