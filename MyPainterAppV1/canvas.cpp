#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>


Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    tool(Pen),
    fill(false),
    drawing(false),
    penWidth(1),
    fillColor(Qt::cyan),
    penColor(Qt::black)
{
}

Canvas::ToolType Canvas::getTool() const
{
    return tool;
}

void Canvas::setTool(const ToolType &value)
{
    tool = value;
}
bool Canvas::getFill() const
{
    return fill;
}

void Canvas::setFill(bool value)
{
    fill = value;
}
int Canvas::getPenWidth() const
{
    return penWidth;
}

void Canvas::setPenWidth(int value)
{
    penWidth = value;
}
QColor Canvas::getFillColor() const
{
    return fillColor;
}

void Canvas::setFillColor(const QColor &value)
{
    fillColor = value;
}
QColor Canvas::getPenColor() const
{
    return penColor;
}

void Canvas::setPenColor(const QColor &value)
{
    penColor = value;
}
bool Canvas::getDrawing() const
{
    return drawing;
}

void Canvas::setDrawing(bool value)
{
    drawing = value;
}

void Canvas::drawLineTo(const QPoint &endPoint)
{

}

void Canvas::drawRectTo(const QPoint &endPoint, bool ellipse)
{

}

void Canvas::eraseUnder(const QPoint &topLeft)
{

}

void Canvas::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
    {
        return;
    }

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255,255,255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0,0), *image);
    *image = newImage;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        drawing = true;
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() && Qt::LeftButton) && drawing)
    {
        if (tool == Pen)
        {
            drawLineTo(event->pos());
        }
        else if (tool == Rectangle)
        {
            drawRectTo(event->pos());
        }
        else if (tool == Ellipse)
        {
            drawRectTo(event->pos(), true);
        }
        else if (tool == Eraser)
        {
            eraseUnder(event->pos());
        }
    }
}

void Canvas::paintEvent(QPaintEvent *event)
{
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height())
    {
        int newWidth = qMax(width()+128, image.width());
        int newHeight = qMax(height()+128,image.height());

        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }

    QWidget::resizeEvent(event); // propagate to parent
}








