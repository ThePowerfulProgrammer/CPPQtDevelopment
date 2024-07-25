#ifndef WIDGET_H
#define WIDGET_H
#include "dragdroplabel.h"

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void clear();

private slots:

    // implement a slot that will respond when we receive the signal from drag and drop class
    void mimeChanged(const QMimeData *mimeData);

private:
    Ui::Widget *ui;
    DragDropLabel *dragDropLabel;
};

#endif // WIDGET_H
