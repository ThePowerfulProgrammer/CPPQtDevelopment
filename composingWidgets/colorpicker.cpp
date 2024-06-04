#include "colorpicker.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

ColorPicker::ColorPicker(QWidget *parent) :
    QWidget(parent)
{
    populateColors();
    setUpUi();
}

QColor ColorPicker::getColor() const
{
    return color;
}

void ColorPicker::setColor(const QColor &value)
{
    color = value;
}

void ColorPicker::button1Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(0).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[0]);
}

void ColorPicker::button2Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(1).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[1]);
}

void ColorPicker::button3Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(2).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[2]);
}

void ColorPicker::button4Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(3).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[3]);
}

void ColorPicker::button5Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(4).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[4]);
}


void ColorPicker::button6Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(5).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[5]);
}

void ColorPicker::button7Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(6).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[6]);
}

void ColorPicker::button8Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(7).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[7]);
}

void ColorPicker::button9Clicked()
{
    QString css = QString("background-color: %1").arg(colorsList.at(8).name());
    label->setStyleSheet(css);
    emit colorChanged(colorsList[8]);
}



void ColorPicker::populateColors()
{
    colorsList << Qt::red << Qt::blue << Qt::black << Qt::green
                  << Qt::cyan << Qt::yellow << Qt::darkRed << Qt::darkBlue
                  << Qt::darkYellow;
}

void ColorPicker::setUpUi()
{
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    grid = new QGridLayout();
    QSizePolicy policy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    QPushButton *button1 = new QPushButton("one", this);
    button1->setSizePolicy(policy);
    QString cssone = QString("background-color: %1").arg(colorsList.at(0).name());
    button1->setStyleSheet(cssone);
    connect(button1, SIGNAL(clicked()), this, SLOT(button1Clicked()));

    QPushButton *button2 = new QPushButton("two", this);
    button2->setSizePolicy(policy);
    QString csstwo = QString("background-color: %1").arg(colorsList.at(1).name());
    button2->setStyleSheet(csstwo);
    connect(button2, SIGNAL(clicked()), this, SLOT(button2Clicked()));

    QPushButton *button3 = new QPushButton("three", this);
    button3->setSizePolicy(policy);
    QString cssthree = QString("background-color: %1").arg(colorsList.at(2).name());
    button3->setStyleSheet(cssthree);
    connect(button3, SIGNAL(clicked()), this, SLOT(button3Clicked()));

    QPushButton *button4 = new QPushButton("four", this);
    button4->setSizePolicy(policy);
    QString cssfour = QString("background-color: %1").arg(colorsList.at(3).name());
    button4->setStyleSheet(cssfour);
    connect(button4, SIGNAL(clicked()), this, SLOT(button4Clicked()));

    QPushButton *button5 = new QPushButton("five", this);
    button5->setSizePolicy(policy);
    QString cssfive = QString("background-color: %1").arg(colorsList.at(4).name());
    button5->setStyleSheet(cssfive);
    connect(button5, SIGNAL(clicked()), this, SLOT(button5Clicked()));

    QPushButton *button6 = new QPushButton("six", this);
    button6->setSizePolicy(policy);
    QString csssix = QString("background-color: %1").arg(colorsList.at(5).name());
    button6->setStyleSheet(csssix);
    connect(button6, SIGNAL(clicked()), this, SLOT(button6Clicked()));

    QPushButton *button7 = new QPushButton("seven", this);
    button7->setSizePolicy(policy);
    QString cssseven = QString("background-color: %1").arg(colorsList.at(6).name());
    button7->setStyleSheet(cssseven);
    connect(button7, SIGNAL(clicked()), this, SLOT(button7Clicked()));

    QPushButton *button8 = new QPushButton("eight", this);
    button8->setSizePolicy(policy);
    QString csseight = QString("background-color: %1").arg(colorsList.at(7).name());
    button8->setStyleSheet(csseight);
    connect(button8, SIGNAL(clicked()), this, SLOT(button8Clicked()));

    QPushButton *button9 = new QPushButton("nine", this);
    button9->setSizePolicy(policy);
    QString cssnine = QString("background-color: %1").arg(colorsList.at(8).name());
    button9->setStyleSheet(cssnine);
    connect(button9, SIGNAL(clicked()), this, SLOT(button9Clicked()));

    grid->addWidget(button1, 0,0);
    grid->addWidget(button2, 0,1);
    grid->addWidget(button3, 0,2);

    grid->addWidget(button4, 1,0);
    grid->addWidget(button5, 1,1);
    grid->addWidget(button6, 1,2);

    grid->addWidget(button7, 2,0);
    grid->addWidget(button8, 2,1);
    grid->addWidget(button9, 2,2);

    label = new QLabel("Color");
    QString css = QString("background-color : #eeeab6");
    label->setFixedHeight(50);
    label->setStyleSheet(css);

    vLayout->addWidget(label);
    vLayout->addLayout(grid);
}

