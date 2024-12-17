#ifndef PAINTDIALOG_H
#define PAINTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>


#include "shapelist.h"

/**
    A horizontal layout:
    Box one will contain the existing shapes
    Box two will be the canvas widget

*/

class PaintDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PaintDialog(QWidget *parent = 0);

signals:
    void mimeChanged(const QMimeData *mimeData = 0); // signal : no code

public slots:


private:
    ShapeList *shapeList;


};

#endif // PAINTDIALOG_H
