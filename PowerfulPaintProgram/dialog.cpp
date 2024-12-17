#include "dialog.h"
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "canvas.h"
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout *layoutOne = new QVBoxLayout;

    toolBar = new QToolBar(this);
    btnOne = new QPushButton(this);
    btnOne->setIcon(QIcon(QPixmap("://Paint Brush Icon.png")));

    btnOne->setIconSize(QSize(20,20));
    penWidthSpinBox = new QSpinBox(this);
    penWidthSpinBox->setRange(1,10);
    penWidthSpinBox->setStyleSheet("width: 20px; height: 20px;font-size: 15px;");
    toolBar->addWidget(btnOne);
    toolBar->addSeparator();
    toolBar->addWidget(penWidthSpinBox);


    layoutOne->addWidget(toolBar);


    QVBoxLayout *layoutTwo = new QVBoxLayout;
    canvas = new Canvas(this);


    QGraphicsView *view = new QGraphicsView;
    view->setScene(canvas);

    layoutTwo->addWidget(view);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutOne);
    mainLayout->addLayout(layoutTwo);

    // signals and slots

    connect(btnOne, SIGNAL(clicked()), this, SLOT(setToolPen()));
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setToolPenWidth()));

    setMinimumSize(QSize(720,880));
    setLayout(mainLayout);
    this->setWindowFlags(Qt::Window);

}


void Dialog::setToolPen()
{
   canvas->setPen();
}

void Dialog::setToolPenWidth()
{
    int width = penWidthSpinBox->value();
    canvas->setPenWidth(width);
}


