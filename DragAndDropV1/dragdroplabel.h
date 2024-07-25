#ifndef DRAGDROPLABEL_H
#define DRAGDROPLABEL_H

#include <QLabel>
#include <QMimeData>

class DragDropLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DragDropLabel(QWidget *parent = 0);

signals:
    void mimeChanged(const QMimeData *mimeData = 0);

public slots:



    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void clear();
};

#endif // DRAGDROPLABEL_H
