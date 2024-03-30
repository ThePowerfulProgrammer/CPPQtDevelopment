#include "delegate.h"
#include <QSlider>
#include <QApplication>
#include <QColor>
#include <QPainter>
#include <QColor>
#include <QFile>



Delegate::Delegate(QObject *parent) :
    QStyledItemDelegate(parent)
{

}

// Overrides how my column is displayed :^)
void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 3)
    {
        QStyleOptionProgressBar progressBarOption;
        progressBarOption.rect = option.rect;
        progressBarOption.minimum = 0;
        progressBarOption.maximum = 10;
        progressBarOption.progress = index.data(Qt::EditRole).toInt();
        progressBarOption.textVisible = true;
        progressBarOption.text = QString::number(progressBarOption.progress) + "%";
        progressBarOption.textAlignment = Qt::AlignCenter;


        QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);

    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}



// when I double click the (row,col), I need to edit the data --> This is how
QWidget* Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QProgressBar *barEditor =  new QProgressBar(parent);
    barEditor->setValue(index.model()->data(index,Qt::EditRole).toInt()); // No Editting here
    barEditor->setTextVisible(false);
    barEditor->setMinimum(0);
    barEditor->setMaximum(10);
    barEditor->setOrientation(Qt::Horizontal);

    return barEditor;

}



// we do not allowing editting therfore I am just populating using model data
void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();

    QProgressBar *slider = static_cast<QProgressBar*>(editor);
    slider->setOrientation(Qt::Horizontal);
    slider->setValue(value);
}


// grab data from (row,col) and submit value to model
void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QProgressBar *slider = static_cast<QProgressBar*>(editor);
    int value = slider->value();

    model->setData(index,value,Qt::EditRole);

}

// Geometry ie: position in space
void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}


