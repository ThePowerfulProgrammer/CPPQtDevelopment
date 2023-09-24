#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H
#include "transaction.h"


class WithDrawal: public Transaction
{
public:
    WithDrawal(double amount);
    // ctor
    // PC: calls parent ctor and itself sets the value of m_Amount(amount)

    QString toString();
    // PC: return string repr of all datamembers, using parent toString() method

    double computeCost();
    // Pure virtual function declared in parent class
    // PC: simply, returns m_Amount * m_Percentage

private:
    double m_Amount; // Amount withdrawn
    double m_Percentage; // charge of the withdrawal, a % of amount withDrawn
};

#endif // WITHDRAWAL_H
