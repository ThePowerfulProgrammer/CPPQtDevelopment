#ifndef DOUBLEDELEGATE_H
#define DOUBLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QString>
#include <QLineEdit>
#include <QPainter>

class DoubleDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit DoubleDelegate(QObject *parent = 0);


    // Alter the standard apperance of a column
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;


signals:

public slots:

};

#endif // DOUBLEDELEGATE_H
