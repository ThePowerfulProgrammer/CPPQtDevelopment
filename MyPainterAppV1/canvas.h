#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);

    enum ToolType{Pen, Rectangle, Ellipse, Eraser};


    ToolType getTool() const;
    void setTool(const ToolType &value);

    bool getFill() const;
    void setFill(bool value);

    int getPenWidth() const;
    void setPenWidth(int value);

    QColor getFillColor() const;
    void setFillColor(const QColor &value);

    QColor getPenColor() const;
    void setPenColor(const QColor &value);

    bool getDrawing() const;
    void setDrawing(bool value);

    QString getLine() const;
    void setLine(const QString &value);

    QString getCap() const;
    void setCap(const QString &value);

    QString getJoin() const;
    void setJoin(const QString &value);

signals:

public slots:

private:

    void drawLineTo(const QPoint &endPoint);
    void drawRectTo(const QPoint &endPoint, bool ellipse = false);
    void eraseUnder(const QPoint &topLeft);

    void resizeImage(QImage *image, const QSize &newSize);

    ToolType tool;
    bool fill;
    bool drawing;
    int penWidth;
    QColor fillColor;
    QColor penColor;
    QPoint lastPoint;
    QRectF lastRect;
    QRectF lastEraserRect;
    QImage image;
    QString line;
    QString cap;
    QString join;


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // CANVAS_H
