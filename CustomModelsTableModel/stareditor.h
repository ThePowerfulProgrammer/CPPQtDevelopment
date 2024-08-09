#ifndef STAREDITOR_H
#define STAREDITOR_H

#include <QWidget>
#include <QMouseEvent>

class StarEditor : public QWidget
{
    Q_OBJECT
public:
    explicit StarEditor(QWidget *parent = 0);

    QSize sizeHint() const;


    int getStarRating() const;
    void setStarRating(int value);

signals:
    void editingFinished();
public slots:


protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    int starRating;
    QPolygon poly;
};

#endif // STAREDITOR_H
