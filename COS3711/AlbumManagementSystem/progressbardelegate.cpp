#include "progressbardelegate.h"
#include <QProgressBar>
#include <QPainter>
ProgressBarDelegate::ProgressBarDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
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
