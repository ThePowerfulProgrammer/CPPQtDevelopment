#include "withdrawal.h"
#include <QString>
#include <QDateTime>

WithDrawal::WithDrawal(double amount): Transaction("Withdrawal", QDateTime::currentDateTime()),
    m_Amount(amount), m_Percentage(0.01)
{
    // ctor
    // is m_Percentage appropriate?
    // My bank charges me R7.50 a month, so I pay them to hold my money, which they
    // can lend out more than once  :(
}

QString WithDrawal::toString()
{
    QString transactionString = Transaction::toString(); // Call parent's toString
    return transactionString + " Amount withdrawn: " + QString::number(m_Amount) +
           " Fee of transaction: " + QString::number(m_Percentage*m_Amount);
}

double WithDrawal::computeCost()
{
    // R100 * 0.01 = R1
    return m_Amount * m_Percentage;
}
