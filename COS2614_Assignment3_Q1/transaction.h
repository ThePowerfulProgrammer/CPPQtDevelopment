#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>
#include <QDateTime>

class Transaction
{
public:
    Transaction(QString type, QDateTime datetime);
    // ctor
    // PC: sets m_Type(type), m_DateTime(datetime)

    QString getType();
    // PC: returns m_Type

    QString toString();
    // PC: returns all datamembers in a readable format

    QDateTime getDateTime();
    // PC: return m_DateTime

    virtual double computeCost() = 0;
    //implementation in child classes
    //PC: retuns cost of each transaction

private:
    QString m_Type;
    QDateTime m_DateTime;
};

#endif // TRANSACTION_H
