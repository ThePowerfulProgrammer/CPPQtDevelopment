#include "doubledelegate.h"

DoubleDelegate::DoubleDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}


QString DoubleDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    bool ok;
    double doubleValue = value.toDouble(&ok);
    if (ok)
    {
        return locale.toString(doubleValue, 'f', 2);  // Format as a fixed-point number with 2 decimal places
    } else
    {
        return QStyledItemDelegate::displayText(value, locale);
    }
}
