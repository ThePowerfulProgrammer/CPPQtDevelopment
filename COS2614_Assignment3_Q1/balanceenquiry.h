#ifndef BALANCEENQUIRY_H
#define BALANCEENQUIRY_H
#include "transaction.h"
#include <QDate>

class BalanceEnquiry: public Transaction
{
public:
    BalanceEnquiry(QDate fDate, QDate tDate);
    // ctor
    // PC: calls parent ctor and itself sets m_FromDate(fDate),  m_ToDate(tDate)

    QString toString();
    // PC: returns string format of all its data members in a readable format

    double computeCost();
    // costs nothing
    // PC: returns cost of transaction

private:
    QDate m_FromDate;
    QDate m_ToDate;
};


#endif // BALANCEENQUIRY_H
