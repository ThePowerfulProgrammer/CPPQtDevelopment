#ifndef PERSONDELEGATE_H
#define PERSONDELEGATE_H

#include <QStyledItemDelegate>

class PersonDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit PersonDelegate(QObject *parent = 0);

signals:

public slots:


    // QAbstractItemDelegate interface
public:
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    // create and return editor
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    // read data from model and display it in editor
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    // change geometry of editor
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    // read data from data and write to model
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // PERSONDELEGATE_H
