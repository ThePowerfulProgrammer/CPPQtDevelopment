#include "doubledelegate.h"
#include <QString>
#include <QDebug>
#include <QFont>

DoubleDelegate::DoubleDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}


void DoubleDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *lineEdit = new QLineEdit;
    if (index.column() == 2)
    {
        double initialValue = index.model()->data(index,Qt::EditRole).toDouble();
        QString doubleRepr = QString::number(initialValue,'f',2);


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

    if (index.column() < 3)
    {

        int value = index.model()->data(index.model()->index(index.row(), 2)).toInt();

        if (value > 199)
        {
            QColor bgColor(255, 0, 0); // Red background color
            QColor fontColor(0, 0, 0); // White font color

            QPen pen(fontColor);
            painter->setPen(pen);
            painter->fillRect(option.rect, bgColor);
        }


    }
}

