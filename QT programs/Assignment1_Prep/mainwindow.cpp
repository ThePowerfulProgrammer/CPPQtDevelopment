#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString passwordGenerator(QString fullName) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    QString password = "";
    int name_length = fullName.length();

    // Choose 5 random non-space characters from the full name
    for (int i = 0; i < 5; i++) {
        int random_index;
        char random_char;

        do {
            random_index = rand() % name_length; // Generate a random index within the range of name_length
            random_char = fullName[random_index]; // Get the character at the random index
        } while (random_char == ' '); // Repeat if the character is a space

        password += random_char; // Append the character to the password string
    }

    return password;
}

int findLastSpace(QString fullName)
{
    int spacePos;
    int location = 0;

    while (location != -1)
        {
            location = fullName.find(' ', location+1);
            if (location != -1)
                {
                    spacePos = location; // location of last " " therefore all after is surname and all before is firstName
                }
        }
    return spacePos;
}

QString generateUsername(QString & name, QString & surname)
{
    QString username = "";
    if ((surname.size() >= 4) && (surname.size() + name.size() >= 5))
        {
            username += surname.substr(0,4);
            username += name.substr(0,1);
        }
    else if ((surname.size() < 4) && (surname.size() + name.size() >=5 ))
        {
            username += surname.substr(0) + name.substr(0,5-surname.size());
        }
    else if (surname.size() + name.size() < 5)
        {
            username += surname.substr(0) + name.substr(0);
            for (int i=0;i<5-(surname.size()+name.size()); i++)
                {
                    username += '0';
                }
        }
    return username;
}

void MainWindow::on_pushButton_clicked()
{
    Qstring password;
    Qstring fullname = ui->lineEdit->text();
    int lastSpacePos;
    QString surname;
    QString name;
    QString username;

    password = passwordGenerator(fullname);

    lastSpacePos = findLastSpace(fullname);


}
