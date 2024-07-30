#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>
#include "person.h"

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PersonModel(QObject *parent = 0);
    ~PersonModel();



signals:
public slots:
private:
    QList<Person * > persons;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // PERSONMODEL_H
