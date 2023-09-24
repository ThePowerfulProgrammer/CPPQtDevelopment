#include "deposit.h"
#include <QDateTime>
#include <QString>

Deposit::Deposit(double amount): Transaction("Deposit", QDateTime::currentDateTime()),
    m_Amount(amount), m_Fee(1.0)
{
    // child class ctor
    // weirddd
}

QString Deposit::toString()
{
    QString transactionString = Transaction::toString(); // Call parent's toString
    return transactionString + " Amount deposited: " + QString::number(m_Amount) +
           " Fee of transaction: " + QString::number(m_Fee);
}

double Deposit::computeCost()
{
    return m_Fee;
}
