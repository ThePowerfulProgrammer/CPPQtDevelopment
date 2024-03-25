#include "delegate.h"
#include <QSlider>
#include <QApplication>

Delegate::Delegate(QObject *parent) :
    QStyledItemDelegate(parent)
{

}


QWidget* Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QProgressBar *barEditor =  new QProgressBar(parent);
    barEditor->setValue(0);
    barEditor->setTextVisible(false);
    barEditor->setMinimum(0);
    barEditor->setMaximum(10);
    barEditor->setOrientation(Qt::Horizontal);

    return barEditor;

}



// when I double click the (row,col), I need to edit the data --> This is how
void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();

    // how do I want to edit data?
    // I need to connect signal and slots to rating and replacement cost

    QProgressBar *slider = static_cast<QProgressBar*>(editor);
    slider->setOrientation(Qt::Horizontal);
    slider->setValue(value);
    slider->setStyleSheet("QProgressBar::chunk {"
                          "     background-color: red;"
                          "}");

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


void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // last column is rating :^)
    if (index.column() == 3)
    {
        QStyleOptionProgressBar progressBar;
        progressBar.rect = option.rect;
        progressBar.minimum = 0;
        progressBar.maximum = 10;
        progressBar.progress = index.data(Qt::EditRole).toInt();


        QProgressBar bar;
        bar.setRange(progressBar.minimum, progressBar.maximum);
        bar.setValue(progressBar.progress);
        bar.setTextVisible(false);

        QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBar, painter, &bar);
    }
}
