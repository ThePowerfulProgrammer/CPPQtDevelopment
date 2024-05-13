#include "doubledelegate.h"



DoubleDelegate::DoubleDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void DoubleDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2)
    {
        int value = index.model()->data(index,Qt::DisplayRole).toInt();
        double doubleRepr = static_cast<double>(value);

        QString displayString = QString::number(doubleRepr, 'f', 2); // Convert the double to a string with 2 decimal places

        QStyleOptionViewItem myOption = option;
        myOption.text = displayString;

        QStyledItemDelegate::paint(painter, myOption, index);
    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

