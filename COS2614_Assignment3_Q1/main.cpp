#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include "deposit.h"
#include "withdrawal.h"
#include "balanceenquiry.h"
#include "savingsaccount.h"
#include "transaction.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);

    Deposit d1(500);
    Deposit d2(3000);
    Deposit d3(300);

    WithDrawal w1(100);
    WithDrawal w2(2500);


    BalanceEnquiry b1(QDate(2023, 7, 20), QDate(2023, 7, 22));
    BalanceEnquiry b2(QDate(2023,8,23), QDate(2023,8,24));

    SavingsAccount savingsAcc("Ash","10101010");

    savingsAcc.addTransaction(&d1);
    savingsAcc.addTransaction(&d2);
    savingsAcc.addTransaction(&d3);

    savingsAcc.addTransaction(&w1);
    savingsAcc.addTransaction(&w2);

    savingsAcc.addTransaction(&b1);
    savingsAcc.addTransaction(&b2);

    qDebug() << "To String: " << "\n";
    qDebug() << savingsAcc.toString() << "\n";


    // Transaction on a date:
    qDebug() << "Transactions for a date: " << "\n";
    QList<Transaction *> list =  savingsAcc.transactionsOnADate(QDate::currentDate());

    for (int i = 0;i<list.size();i++)
    {
        qDebug() << list[i]->toString() << "\n";

    }


    // Total cost of all transactions
    qDebug() << "Total cost of all transactions: " << savingsAcc.totalTransactionCost() ;

    // Most Frequent Transactions
    qDebug() << "Most Frequenct Transaction: " << savingsAcc.frequentTransactionType();

    return a.exec();
}
