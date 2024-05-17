#include "colordelegate.h"

ColorDelegate::ColorDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
    // ctor
}

void ColorDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() < 3)
    {
        QStyleOptionViewItem opt = option;

        int value = index.model()->data(index.model()->index(index.row(),2)).toInt();

        if (value > 199)
        {
            QColor color(125,0,0,100);
            QFont font("Oswald",-1,1,true);

            opt.font = font;
            opt.backgroundBrush = Qt::NoBrush;
            painter->fillRect(opt.rect,color);
        }
        else
        {
            QStyledItemDelegate::paint(painter,option,index);
        }
    }
}
