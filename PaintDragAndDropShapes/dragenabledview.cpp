#include "dragenabledview.h"
#include <QDebug>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>

DragEnabledView::DragEnabledView(QWidget *parent )
    : QGraphicsView(parent)
{

    qDebug() << "Parent X: "<< this->size().width() << "\n";
    qDebug() << "Parent Y: " << this->size().height()  << "\n";
    setAcceptDrops(true);
}


void DragEnabledView::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << " Drag enter event \n";
    event->acceptProposedAction();
}

void DragEnabledView::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
    qDebug() << "Moving Drag object \n";
}

void DragEnabledView::dragLeaveEvent(QDragLeaveEvent *event)
{
    Q_UNUSED(event)

    qDebug() << "Left drag space \n";

    for (int i=0;i<this->scene()->items().size(); i++)
    {
        QGraphicsItem *item = this->scene()->items()[i];

        this->scene()->removeItem(item);
    }

    this->scene()->clear();
}

void DragEnabledView::dropEvent(QDropEvent *event)
{
    qDebug() << "Object dropped in \n";

    const QMimeData *mimeData = event->mimeData();

    qDebug() << mimeData->text() << "\n";
    qDebug() << "Some item was just dropped onto the scene \n";
    qDebug() << "Text: " << mimeData->property("text") << "\n"; // once I have the name of the shape, I can create a generic implementation

    QVariant *variant = new QVariant(mimeData->property("text")) ;
    qDebug() << variant->toString() << " \n";

    // keep it simple and use a if-else conditional
    if (variant->toString() == "Square")
    {
        qDebug() << "Square identified \n";

        float scene_x = event->pos().x();
        float scene_y = event->pos().y();
        float width = 50;
        float height = 50;

        QGraphicsRectItem *rectItem = new QGraphicsRectItem(QRectF(scene_x, scene_y, width, height) );
        rectItem->setBrush(QBrush(QColor(0,0,0)));
        rectItem->setFlag(QGraphicsItem::ItemIsMovable);
        rectItem->setFlag(QGraphicsItem::ItemIsSelectable);

        this->scene()->addItem(rectItem);

    }
    else if (variant->toString() == "Circle" )
    {
        qDebug() << "Circle identified \n";

        float scene_x = event->pos().x();
        float scene_y = event->pos().y();
        float width = 50;
        float height = 50;

        QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(QRectF(scene_x, scene_y,width,height));
        ellipseItem->setFlag(QGraphicsItem::ItemIsMovable);
        ellipseItem->setFlag(QGraphicsItem::ItemIsSelectable);
        ellipseItem->setBrush(QBrush(QColor(Qt::cyan)));

        this->scene()->addItem(ellipseItem);
    }
    else
    {
        // we can for now ignore the drop action
        qDebug() << "Item not identified as a square or circle \n";
    }


}








