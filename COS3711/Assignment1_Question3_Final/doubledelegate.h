#ifndef DOUBLEDELEGATE_H
#define DOUBLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QString>

class DoubleDelegate : public QStyledItemDelegate
{

public:
    explicit DoubleDelegate(QObject *parent = 0);
    QString displayText(const QVariant &value, const QLocale &locale) const;
signals:

public slots:

};

#endif // DOUBLEDELEGATE_H
