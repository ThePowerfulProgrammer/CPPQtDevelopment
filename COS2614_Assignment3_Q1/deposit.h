#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "transaction.h"

class Deposit: public Transaction
{
public:
    Deposit(double amount);
    // PC: calls parent class ctor to set members and sets m_Amount(amount

    QString toString();
    // PC: returns values of all data members in a readable format

    double computeCost();
    // Pure virtual function declared in parent class
    // PC: simply, returns m_Fee

private:
    double m_Amount; // deposit amount
    double m_Fee; // cost of each deposit
};

#endif // DEPOSIT_H
