#ifndef SHAPECANVAS_H
#define SHAPECANVAS_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class ShapeCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit ShapeCanvas(QWidget *parent = 0);
    enum Shape {Polygon, Rect, RoundedRect, Ellipse, Pie, Chord,
               Text, Pixmap};

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    Shape getShape() const;
    void setShape(const Shape &value);

    QPen getPen() const;
    void setPen(const QPen &value);

    QBrush getBrush() const;
    void setBrush(const QBrush &value);

signals:

public slots:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Shape shape;
    QPen pen;
    QBrush brush;

};

#endif // SHAPECANVAS_H
