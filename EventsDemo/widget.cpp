#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "MOuse Pressed @: " << event->pos() << "\n";
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "MOuse Released@: " << event->pos() << "\n";
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "MOuse Moved@: " << event->pos() << "\n";
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "Widget about to close" << "\n";
    event->accept();
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "Contect Menu Event activated upon right mouse click: " << "\n";

    QMenu *menu = new QMenu(this);
    menu->addAction(tr("Action1"));
    menu->addAction(tr("Action2"));

    menu->popup(mapToGlobal(event->pos()  ));

    qDebug() << "Event reason: " << event->reason() << "\n";
}


void Widget::enterEvent(QEvent *event)
{
    qDebug() << "Entered Widget " << "\n";
}

void Widget::leaveEvent(QEvent *event)
{
    qDebug() << "Exit Widget" << "\n";
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed: " << event->key() << " : " << event->text() << "\n";

    if (event->modifiers()&Qt::ShiftModifier)
    {
        qDebug() << "Shift + " << event->text() << "\n";

        if (event->key() == Qt::Key_A)
        {
            qDebug() << "If successful" << "\n";
        }
    }

    if (event->modifiers()&Qt::ControlModifier)
    {
        qDebug() << "Ctrl + " << event->text() << "\n";
    }

    if (event->modifiers()&Qt::AltModifier)
    {
        qDebug() << "Alt + " << event->text() << "\n";
    }
}


void Widget::paintEvent(QPaintEvent *)
{
    qDebug() << "paint widget or build widget" << "\n";
}

void Widget::resizeEvent(QResizeEvent *)
{
    qDebug() << "Window resized!: " << "\n";
}
