#include "dialog.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "resizeablerect.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent, Qt::Window)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    ResizeableRect *rect = new ResizeableRect;
    rect->setRect(QRect(350,250,100,100));
    rect->setBrush(QBrush(QColor(4,27,255)));

    QGraphicsScene *scene = new QGraphicsScene;
    scene->addItem(rect);
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);

    mainLayout->addWidget(view);

    setMinimumWidth(800);
    setMinimumHeight(600);
    setLayout(mainLayout);
}