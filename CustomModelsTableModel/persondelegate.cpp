#include "persondelegate.h"
#include <QComboBox>
#include <QPixmap>
#include <personmodel.h>

PersonDelegate::PersonDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{

}


QSize PersonDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option,index).expandedTo(
                QSize(64,option.fontMetrics.height()+10)
                );
}


// The actual editor widget you want to use when you edit data
QWidget *PersonDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2)
    {
        QComboBox *editor = new QComboBox(parent);

        foreach (QString color, QColor::colorNames()) {
            QPixmap mPix(50,50);
            mPix.fill(QColor(color));
            editor->addItem(QIcon(mPix),color);
        }

        return editor;
    }
    return QStyledItemDelegate::createEditor(parent,option,index);

}

// read from model and place in editor
void PersonDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == 2)
    {
        QComboBox *combo = static_cast<QComboBox *>(editor);
        int idx = QColor::colorNames().indexOf(index.data(Qt::DisplayRole).toString());
        combo->setCurrentIndex(idx);
    }
    else
    {
        QStyledItemDelegate::setEditorData(editor,index);
    }
}


// now read data from editor and write to model
void PersonDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == 2)
    {
        QComboBox *box = static_cast<QComboBox *>(editor);
        model->setData(index,box->currentText(), Qt::EditRole);
    }
    else
    {
        QStyledItemDelegate::setModelData(editor,model,index);
    }
}

void PersonDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}




void PersonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2)
    {
        if (option.state && QStyle::State_Selected)
        {
            painter->fillRect(option.rect,option.palette.highlight());
        }

        QString favColor = index.data(PersonModel::FavoriteColorRole).toString();

        painter->save();

        painter->setBrush(QBrush(QColor(favColor)));

        painter->drawRect(option.rect.adjusted(3,3,-3,-3));

        QSize textSize = option.fontMetrics.size(Qt::TextSingleLine, favColor);

        painter->setBrush(QBrush(QColor(Qt::white)));

        int widthAdjusted = (option.rect.width() - textSize.width())/2 - 3;
        int heightAdjusted = (option.rect.height() - textSize.height())/2;

        painter->drawRect(option.rect.adjusted(widthAdjusted, heightAdjusted, -widthAdjusted, -heightAdjusted));

        painter->drawText(option.rect, favColor, Qt::AlignHCenter|Qt::AlignVCenter);

        painter->restore();
    }
    else
    {
        QStyledItemDelegate::paint(painter,option,index);
    }

}








