#include "delegate.h"

Delegate::Delegate(QObject *parent) :
    QStyledItemDelegate(parent)
{

}


QWidget* Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QProgressBar *bar =  new QProgressBar(parent);
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}
