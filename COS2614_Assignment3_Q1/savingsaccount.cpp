#include "savingsaccount.h"
#include <QMap>
#include <QDateTime>
#include <QDebug>


SavingsAccount::SavingsAccount(QString name, QString num): m_CustomerName(name), m_AccountNumber(num),
    m_TransactionList()
{
    // ctor :)
}

void SavingsAccount::addTransaction(Transaction *t)
{
    m_TransactionList.append(t);
}

double SavingsAccount::totalTransactionCost()
{
    // traverse m_TransactionList: QList<Transaction> and add up all the associated costs
    double totalTCost = 0;
    for (int i=0;i<m_TransactionList.size(); i++)
    {
        if (m_TransactionList[i]->computeCost() != 0)
        {
            totalTCost += m_TransactionList[i]->computeCost();
        }
    }
    return totalTCost;
}

QString SavingsAccount::frequentTransactionType()
{
    QMap<QString, int> typeCounts;
    typeCounts["Deposit"] = 0;
    typeCounts["WithDrawal"] = 0;
    typeCounts["BalanceEnquiry"] = 0;

    for (int i=0;i<m_TransactionList.size();i++)
    {
        if (dynamic_cast<Deposit*>(m_TransactionList[i]) != 0)
        {
            //qDebug() << "Deposit" << "\n";
            typeCounts["Deposit"]++;
        }
        else if (dynamic_cast<WithDrawal*>(m_TransactionList[i]) != 0)
        {
            //qDebug() << "WithDrawal" << "\n";
            typeCounts["WithDrawal"]++;
        }
        else if (dynamic_cast<BalanceEnquiry*>(m_TransactionList[i]) != 0)
        {
            //qDebug() << "BalanceEnquiry" << "\n";
            typeCounts["BalanceEnquiry"]++;
        }
    }

    if (typeCounts.find("Deposit").value() == typeCounts.find("WithDrawal").value() &&
            typeCounts.find("WithDrawal").value() == typeCounts.find("BalanceEnquiry").value())
    {
        return "Equal frequency of Transactions";
    }


    QString mostFrequentType;
    int maxCount = -1;

    QMap<QString, int>::const_iterator iter;

    for (iter = typeCounts.constBegin(); iter != typeCounts.constEnd(); ++iter) {
        if (iter.value() > maxCount)
        {
            maxCount = iter.value();
            mostFrequentType = iter.key();

        }
    }

    return mostFrequentType;

}




QList<Transaction*> SavingsAccount::transactionsOnADate(QDate date)
{
    QList<Transaction*> transactionsForDate;
    QDate when = date;

    for (int i=0;i<m_TransactionList.size();i++)
    {
        Transaction *t = m_TransactionList[i];
        QDate transactionDate = t->getDateTime().date();

        if (transactionDate == when)
        {
            transactionsForDate.append(t);
        }
    }

    return transactionsForDate;
}

QString SavingsAccount::toString()
{
    QString result = "Overview of savingsAccount, customerName: " + m_CustomerName + ", accountNumber: " + m_AccountNumber + ", all transactions:\n";

    for (int i=0;i<m_TransactionList.size();i++)
    {
         result += m_TransactionList[i]->toString() + "\n";
    }

    return result;
}


