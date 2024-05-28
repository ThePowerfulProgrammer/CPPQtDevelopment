#ifndef PARENTLINEEDIT_H
#define PARENTLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QDebug>

class ParentLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit ParentLineEdit(QWidget *parent = 0);

signals:

public slots:


protected:
    void keyPressEvent(QKeyEvent *event);

private:


};

#endif // PARENTLINEEDIT_H
