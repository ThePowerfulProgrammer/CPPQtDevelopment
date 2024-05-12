#include "progressbardelegate.h"
#include <QProgressBar>
#include <QPainter>
#include <QSpinBox>

ProgressBarDelegate::ProgressBarDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

// Double click the editor and createEditor() runs
QWidget *ProgressBarDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *boxEditor = new QSpinBox(parent);
    boxEditor->setValue(index.model()->data(index,Qt::EditRole).toInt());
    boxEditor->setRange(0,10);
    return boxEditor;
}

void ProgressBarDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();

    QSpinBox *boxEditor = new QSpinBox;
    boxEditor->setValue(value);
}


void ProgressBarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 3)
    {
        int value = index.model()->data(index, Qt::EditRole).toInt();

        QProgressBar progressBar;
        progressBar.setStyleSheet("QProgressBar {"
                                  "border: 2px solid grey;"
                                  "border-radius: 5px;"
                                  "text-align: center;"
                                  "background: white;"
                                 "}"
                                 "QProgressBar::chunk {"
                                  "background-color: cyan;"
                                 "}");
        progressBar.setRange(0, 10);
        progressBar.setValue(value);
        progressBar.setGeometry(option.rect);

        painter->save();
        painter->translate(option.rect.topLeft());
        progressBar.render(painter);
        painter->restore();
    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}
