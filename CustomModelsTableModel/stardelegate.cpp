#include "stardelegate.h"
#include <QPainter>

StarDelegate::StarDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
    poly << QPoint(0, 85) << QPoint(75, 75)
         << QPoint(100, 10) << QPoint(125, 75)
         << QPoint(200, 85) << QPoint(150, 125)
         << QPoint(160, 190) << QPoint(100, 150)
         << QPoint(40, 190) << QPoint(50, 125)
         << QPoint(0, 85);
}


void StarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if (index.column() == 3)
    {
        QRect rect = option.rect.adjusted(10,10,-10,-10);

        int starNumber = index.data().toInt();
        while (starNumber > 5)
        {
            starNumber --;
        }

        painter->save();

        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(Qt::green));

        painter->translate(rect.x(), rect.y());

        painter->scale(0.1,0.1);

        for (int i=0;i<starNumber;i++)
        {
            painter->drawPolygon(poly);
            painter->translate(220,0);
        }

        painter->restore();

    }
}

QSize StarDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option,index);
}

QWidget *StarDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 3)
    {
        int starRating = index.data().toInt();
        StarEditor *editor = new StarEditor(parent);
        editor->setStarRating(starRating);
        connect(editor,SIGNAL(editingFinished()), this, SLOT(commitAndCloseEditor()));
        return editor;
    }
    else
    {
        return QStyledItemDelegate::createEditor(parent,option,index);
    }
}

void StarDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column() == 3)
    {
        int starRating = index.data().toInt();
        StarEditor *starEditor = qobject_cast<StarEditor *>(editor);
        starEditor->setStarRating(starRating);
    }
    else{
        QStyledItemDelegate::setEditorData(editor,index);
    }
}

void StarDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == 3)
    {
        StarEditor *stareditor = qobject_cast<StarEditor*>(editor);

        model->setData(index, QVariant::fromValue(stareditor->getStarRating()), Qt::EditRole             );
    }
    else
    {
        QStyledItemDelegate::setModelData(editor,model,index);
    }
}

void StarDelegate::commitAndCloseEditor()
{
    StarEditor *editor = qobject_cast<StarEditor*>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}


