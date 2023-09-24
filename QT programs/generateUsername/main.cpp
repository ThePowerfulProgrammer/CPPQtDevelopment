/*#include <QApplication>
#include <QString>
#include <QInputDialog>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);
    QStringList hobbits,yesno;
    hobbits << "Frodo" << "Bilbo" << "SamWise" << "Merry" << "Pippin";
    yesno << "yes" << "no";
    QString outcome, more,title("Hobbit selector");
    QString query("Pick your favourite hobbit");
    do
    {
        QString pick = QInputDialog::getItem(0, title, query,hobbits);
        outcome = QString("You picked %1, try again?").arg(pick);
        more = QInputDialog::getItem(0, "Pick a hobbit", outcome, yesno,1,false);
    } while (more == "yes");

} working code*/

#include <QStringList>
#include <QDebug>
#include <QString>
#include <ctime>


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




int main()
{
    QString password;
    QString fullName = "Ashish Ramnath";
    int lastSpace;
    QString surname;
    QString name;
    QString username;

    password = passwordGenerator(fullName);
    lastSpace = findLastSpace(fullName);

    surname = fullName.mid(lastSpace+1);
    name = fullName.mid(0, lastSpace);
    name = name.toLower();
    username = generateUsername(name,surname);

    qDebug() << "Password:" << password;
    qDebug() << "Username:" << username;
    return 0;
}
