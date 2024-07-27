#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>


Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    tool(Pen),
    fill(false),
    drawing(false),
    penWidth(1),
    fillColor(Qt::blue),
    penColor(Qt::black),
    lastRect(QRectF(0,0,0,0)),
    lastEraserRect(QRectF(0,0,0,0)),
    line("SolidLine"),
    cap("RoundCap"),
    join("RoundJoin")
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
    QPainter painter(&image);
    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawLine(lastPoint, endPoint);
    qDebug() << "Last Point: " << lastPoint.x() << lastPoint.y() << " EndPoint: " << endPoint.x() << endPoint.y() << "\n";
    int adjustment = penWidth + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-adjustment,-adjustment,+adjustment,+adjustment));
    lastPoint = endPoint;
}

void Canvas::drawRectTo(const QPoint &endPoint, bool ellipse)
{
    QPainter painter(&image);
    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    if (fill)
    {
        painter.setBrush(fillColor);
    }
    else
    {
        painter.setBrush(Qt::NoBrush);
    }

    if (!ellipse)
    {
        painter.drawRect(QRect(lastPoint, endPoint));
    }
    else
    {
        painter.drawEllipse(QRect(lastPoint,endPoint));
    }

    if (drawing)
    {
        painter.setPen(QPen(Qt::white, penWidth+3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

        if (fill)
        {
            painter.setBrush(Qt::white);
        }
        else
        {
            painter.setBrush(Qt::NoBrush);
        }

        if (!ellipse)
        {
            painter.drawRect(lastRect);
        }
        else
        {
            painter.drawEllipse(lastRect);
        }

        painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.setBrush(fillColor);
    }

    lastRect = QRectF(lastPoint,endPoint);

    update();


}

void Canvas::eraseUnder(const QPoint &topLeft)
{
    QPainter painter(&image);

    painter.setBrush(Qt::white);
    painter.setPen(Qt::white);
    painter.drawRect(lastEraserRect);

    QRect currentRect(topLeft, QSize(100,100));
    painter.setBrush(Qt::white);
    painter.setPen(Qt::white);
    painter.drawRect(lastEraserRect);

    painter.setBrush(Qt::black);
    painter.setPen(Qt::black);
    painter.drawRect(currentRect);

    painter.setBrush(Qt::black);
    painter.setPen(Qt::black);
    painter.drawRect(currentRect);

    lastEraserRect = currentRect;

    if (!drawing)
    {
        painter.setBrush(Qt::white);
        painter.setPen(Qt::white);
        painter.drawRect(lastEraserRect);
        lastEraserRect = QRect(0,0,0,0);

    }
    update();

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
QString Canvas::getJoin() const
{
    return join;
}

void Canvas::setJoin(const QString &value)
{
    join = value;
}

QString Canvas::getCap() const
{
    return cap;
}

void Canvas::setCap(const QString &value)
{
    cap = value;
}

QString Canvas::getLine() const
{
    return line;
}

void Canvas::setLine(const QString &value)
{
    line = value;
}


void Canvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        drawing = true;
    }
}



void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
    {

        if (tool == Pen)
        {
            drawLineTo(event->pos());
        }
        if (tool == Rectangle)
        {
            drawRectTo(event->pos());
        }
        if (tool == Ellipse)
        {
            drawRectTo(event->pos(), true);
        }
        if (tool == Eraser)
        {
            eraseUnder(event->pos());
        }

    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if ((event->button() == Qt::LeftButton && drawing) )
    {
        drawing = false;
        if (tool == Pen)
        {
            drawLineTo(event->pos());
        }
        if (tool == Rectangle)
        {
            drawRectTo(event->pos());
        }
        if (tool==Ellipse)
        {
            drawRectTo(event->pos(), true);
        }
        if (tool == Eraser)
        {
            eraseUnder(event->pos());
        }

        lastRect = QRect(0,0,0,0);
    }
}


void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rectToDraw = event->rect();
    painter.drawImage(rectToDraw, image, rectToDraw);
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








