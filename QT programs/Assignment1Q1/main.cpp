#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <ctime>
#include <QInputDialog>

// Generates User passwsord from fullName, PDF does not state (repetitions not allowed)
QString passwordGenerator(QString fullName)
{
    srand(time(NULL));

    QString password = "";
    int nameLength = fullName.size();

    // Choose 5 random non-space chars from fullName
    for (int i=0; i<5; i++)
    {
        int randomIndex;
        QChar randomChar;

        do
        {
            randomIndex = rand() % nameLength;
            randomChar = fullName.at(randomIndex);
        } while (randomChar == ' ');
        password.append(randomChar);
    }
    return password;
}

// Function that returns index of last " "
int findLastSpace(QString fullName)
{
    int spacePos;
    int location = 0;

    while (location != -1)
    {
        location = fullName.indexOf(' ', location+1);
        if (location != -1)
        {
            spacePos = location;
        }
    }
    return spacePos;
}

// Once we break down username into name and surname, we create a Username
QString generateUsername(QString & name, QString & surname)
{
    QString username = "";
    if ((surname.size() >= 4) && (surname.size() + name.size() >= 5))
        {
            username += surname.mid(0,4);
            username += name.mid(0,1);
        }
    else if ((surname.size() < 4) && (surname.size() + name.size() >=5 ))
        {
            username += surname.mid(0) + name.mid(0,5-surname.size());
        }
    else if (surname.size() + name.size() < 5)
        {
            username += surname.mid(0) + name.mid(0);
            for (int i=0;i<5-(surname.size()+name.size()); i++)
                {
                    username += '0';
                }
        }
    return username;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString fullName = QInputDialog::getText(0, "Input Dialog", "Enter FullName:");

    QString password = passwordGenerator(fullName);
    int lastSpace = findLastSpace(fullName);

    QString surname = fullName.mid(lastSpace+1);
    QString name = fullName.mid(0, lastSpace);

    name = name.toLower();

    QString username = generateUsername(name,surname);
    QMessageBox::information(0,"User data", "Password: "+password+" Username: "+username);


    return EXIT_SUCCESS;
}
