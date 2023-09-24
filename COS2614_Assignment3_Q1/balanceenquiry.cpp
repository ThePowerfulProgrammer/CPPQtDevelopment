#include "balanceenquiry.h"
#include <QDateTime>
#include <QString>

//                            Format:(dd.MM.yyyy)
BalanceEnquiry::BalanceEnquiry(QDate fDate, QDate tDate): Transaction("BalanceEnquiry", QDateTime::currentDateTime()),
    m_FromDate(fDate), m_ToDate(tDate)
{
    // ctor
}

// lil weird
QString BalanceEnquiry::toString()
{
    QString transactionString = Transaction::toString(); // Call parent's toString
    QString fromDate = m_FromDate.toString("dd.MM.yyyy");
    QString toDate = m_ToDate.toString("dd.MM.yyyy");

    return transactionString + "\n " + "From: " + fromDate + " to: " + toDate;
}

double BalanceEnquiry::computeCost()
{
    return 0.0;
}

