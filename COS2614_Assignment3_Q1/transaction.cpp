#include "transaction.h"


Transaction::Transaction(QString type, QDateTime datetime)
            : m_Type(type), m_DateTime(datetime)
{
    // m_DateTime = QDateTime::currentDateTime() ?
    // ctor
}


QString Transaction::getType()
{
    // return m_Type member
    return m_Type;
}

QString Transaction::toString()
{
    // How do I convert QDateTime to QString?
    QString customFormat = "dd.MM.yyyy hh:mm AP";
    return "Type: " + getType() + " " + "Date: " + m_DateTime.toString(customFormat);
}


QDateTime Transaction::getDateTime()
{
    // return m_DateTime member
    return m_DateTime;
}




