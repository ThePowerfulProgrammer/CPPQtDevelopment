#include "shapelist.h"
#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QGraphicsView>

ShapeList::ShapeList(QWidget *parent) :
    QListWidget(parent)
{
   // populate the widget

    itemOne = new QListWidgetItem;
    itemTwo = new QListWidgetItem;


    itemOne->setText("Circle");
    itemOne->setIcon(QIcon(QPixmap("://images/circle icon.png")));

    itemTwo->setText("Square");
    itemTwo->setIcon(QIcon("://images/square icon.png"));

    this->addItem(itemOne);
    this->addItem(itemTwo);


    setSelectionMode(QAbstractItemView::SingleSelection);

    setDragEnabled(true);
}

void ShapeList::helloWorld()
{
    qDebug() << "Hello world \n";
}


void ShapeList::startDrag(Qt::DropActions supportedActions)
{
    Q_UNUSED(supportedActions)
    QList<QListWidgetItem*> items = selectedItems();

    if (items.count() > 0)
    {

        qDebug() << "Item selected \n";
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        QListWidgetItem *item = items[0];

        int key = item->data(Qt::UserRole).toInt();

        mimeData->setProperty("Key", QVariant::fromValue(key));
        mimeData->setProperty("text", item->text());

        itemOne->setData(Qt::UserRole, key);
        itemTwo->setData(Qt::UserRole, key);
        drag->setMimeData(mimeData);
        QPixmap pix = item->icon().pixmap(50,50);
        drag->setPixmap(pix);

        drag->setHotSpot(pix.rect().center()); // centre the cursor


        qDebug() << item->text() << "\n";

        if (drag->exec() == Qt::IgnoreAction)
        {
            qDebug() << "Ignored " << "\n";
        }

        // If I grabbed a shape --> I then need to drag and drop onto the scene and have the shape show up with some set params

    }




}
