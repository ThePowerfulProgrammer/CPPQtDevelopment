#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "transaction.h"
#include "deposit.h"
#include "withdrawal.h"
#include "balanceenquiry.h"

#include <QString>
#include <QList>
#include <QDate>


class SavingsAccount
{
public:
    SavingsAccount(QString name, QString num);
    // ctor

    void addTransaction(Transaction *t);
    // PC: adds transaction to m_TransactionList

    double totalTransactionCost();
    // PC: returns combined cost of all the transactions in m_TransactionList

    QString frequentTransactionType();
    // PC: return the type of transaction that is done most frequently in a savings account

    QList<Transaction *> transactionsOnADate(QDate date);
    // PC: returns a list of the transactions carried out on a given date

    QString toString();
    // PC: return string repr of all datamembers, does not inherit toString()



private:
    QString m_CustomerName;
    QString m_AccountNumber;
    QList<Transaction *> m_TransactionList;
};

#endif // SAVINGSACCOUNT_H
