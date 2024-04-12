#ifndef PROGRESSBARDELAGATE_H
#define PROGRESSBARDELAGATE_H

#include <QStyledItemDelegate>

class ProgressBarDelagate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ProgressBarDelagate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

public slots:

};

#endif // PROGRESSBARDELAGATE_H
