#include "personmodel.h"

PersonModel::PersonModel(QObject *parent) :
    QAbstractListModel(parent)
{
    //Populate with initial data
    persons.append (new Person("Jamie Lannister","red",33));
    persons.append(new Person("Marry Lane","cyan",26));
    persons.append(new Person("Steve Moors","yellow",44));
    persons.append(new Person("Victor Trunk","dodgerblue",30));
    persons.append(new Person("Ariel Geeny","blue",33));
    persons.append(new Person("Knut Vikran","lightblue",26));

}


int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return persons.size();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= persons.count())
    {
        return QVariant();
    }

    Person *person = persons[index.row()];

    if (role == Qt::DisplayRole)
    {
        return person->names() + " " + QString::number(person->age()) + " " + person->favoriteColor();
    }

    if (role == Qt::EditRole)
    {
        return person->names() + " " + QString::number(person->age()) + " " + person->favoriteColor();
    }

    if (role == Qt::ToolTipRole)
    {
        return person->names() + " " + QString::number(index.row());
    }

    return QVariant();

}


PersonModel::~PersonModel()
{
    qDeleteAll(persons);
}


bool PersonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
    {
        return false;
    }

    Person *person = persons[index.row()];
    bool somethingChanged = false;

    switch (role)
    {
        case Qt::EditRole:
        {
            if (person->names() != value.toString())
            {
                person->setNames(value.toString());
                somethingChanged = true;

            }
        }
    }


    if (somethingChanged)
    {
        emit dataChanged(index, index);
        return true;
    }

    return false;


}

QVariant PersonModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal)
    {
        return QString("Person names");
    }

    return QString("Person %1").arg(section);
}

Qt::ItemFlags PersonModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return QAbstractItemModel::flags(index);
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void PersonModel::addPerson(Person *person)
{
    const int index = persons.size();
    beginInsertRows(QModelIndex(), index,index);
    persons.append(person);
    endInsertRows();
}

void PersonModel::removePerson(QModelIndex index)
{
    beginRemoveRows(QModelIndex(), index.row(), index.row());
    persons.removeAt(index.row());
    endRemoveRows();
}






