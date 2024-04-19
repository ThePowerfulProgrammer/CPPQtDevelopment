#include "colordelegate.h"
#include <QVariant>
#include <QDebug>
#include <QColor>

ColorDelegate::ColorDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void ColorDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;


    if (index.column() < 3)
    {
        QVariant value =  index.model()->data(index.model()->index(index.row(),2));

        if (value.toInt() >= 200 )
        {
            QColor color;
            color.setRgb(255,0,0);
            painter->fillRect(option.rect,color);
            opt.backgroundBrush = Qt::NoBrush;
        }
        else if (editedRows.contains(index.row()))
        {
            QColor color;
            color.setRgb(255,0,0);
            painter->fillRect(option.rect,color);
            opt.backgroundBrush = Qt::NoBrush;
        }
        else
        {
            // I just want the value
            QStyledItemDelegate::paint(painter,option,index);
            return;
        }


        QStyledItemDelegate::paint(painter,opt,index);
    }


}

void ColorDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QStyledItemDelegate::setModelData(editor, model, index);

    int row = index.row();
    if (editedRows.find(row) == editedRows.constEnd() )
    {
        editedRows.insert(row);
    }
    else
    {
        editedRows.remove(row);
    }


}
