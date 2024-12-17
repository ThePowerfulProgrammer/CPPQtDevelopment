#ifndef SHAPELIST_H
#define SHAPELIST_H

#include <QListWidget>

class ShapeList : public QListWidget
{
    Q_OBJECT
public:
    explicit ShapeList(QWidget *parent = 0);

signals:

public slots:
    void helloWorld();


    // QAbstractItemView interface
protected:
    void startDrag(Qt::DropActions supportedActions);

private:
    QListWidgetItem *itemOne;
    QListWidgetItem *itemTwo;
};

#endif // SHAPELIST_H
