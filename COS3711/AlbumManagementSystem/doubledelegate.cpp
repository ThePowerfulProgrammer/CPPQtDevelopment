#include "doubledelegate.h"
#include <QString>
#include <QDebug>

DoubleDelegate::DoubleDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}


void DoubleDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2)
    {
        double initialValue = index.model()->data(index,Qt::EditRole).toDouble();
        QString doubleRepr = QString::number(initialValue,'f',2);

        QLineEdit *lineEdit = new QLineEdit;
        lineEdit->setPlaceholderText(doubleRepr);
        lineEdit->setGeometry(option.rect);

        lineEdit->setStyleSheet("QLineEdit {"
                                "border: 1px solid grey;"
                                "text-align:center;"
                                "background: white;"
                                "font: bold 14px;"
                                "font-family: Helvetica;"
                                "color: black;"
                                "}");

        painter->save();
        painter->translate(option.rect.topLeft());
        lineEdit->render(painter);
        painter->restore();
    }
    else
    {
        QStyledItemDelegate::paint(painter,option,index);
    }
}

