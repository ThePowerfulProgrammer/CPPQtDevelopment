#ifndef DOUBLEDELEGATE_H
#define DOUBLEDELEGATE_H

#include <QStyledItemDelegate>

class DoubleDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit DoubleDelegate(QObject *parent = 0);


    // edit the basic views of the column
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;


signals:

public slots:

};

#endif // DOUBLEDELEGATE_H
