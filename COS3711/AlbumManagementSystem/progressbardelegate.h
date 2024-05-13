#ifndef PROGRESSBARDELEGATE_H
#define PROGRESSBARDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QModelIndex>
#include <QStyleOptionViewItem>

class ProgressBarDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ProgressBarDelegate(QObject *parent = 0);

    // The design
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    // The manner in which the user interacts
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    // Sets the default data for editing
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

//    void setModelData(QWidget *editor, QAbstractItemModel *model,
//                      const QModelIndex &index) const;

//    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
//                              const QModelIndex &index) const override;
signals:

public slots:

};

#endif // PROGRESSBARDELEGATE_H
