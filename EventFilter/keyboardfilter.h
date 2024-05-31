#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H

#include <QObject>

class KeyboardFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardFilter(QObject *parent = 0);

signals:

public slots:


    // QObject interface
public:
    bool eventFilter(QObject *watcher, QEvent *event);
};

#endif // KEYBOARDFILTER_H
