#ifndef COLORDELEGATE_H
#define COLORDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QSet>

class ColorDelegate : public QStyledItemDelegate
{
public:
    explicit ColorDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;


signals:

public slots:

private:
    mutable QSet<int> editedRows;

};

#endif // COLORDELEGATE_H
