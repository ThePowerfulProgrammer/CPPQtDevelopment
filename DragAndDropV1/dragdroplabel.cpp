#include "dragdroplabel.h"
#include <QDragEnterEvent>

DragDropLabel::DragDropLabel(QWidget *parent) :
    QLabel(parent)
{
    setMinimumSize(100,100);
    setAlignment(Qt::AlignCenter);
    setAcceptDrops(true);
    setText("DROP SPACE");
    setBackgroundRole(QPalette::Dark);
}

// an event handler that is called when a drag is in progress and the mouse enters the widget
void DragDropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    setText(tr("DROP YOUR DATA HERE"));
    setBackgroundRole(QPalette::Highlight);
    event->acceptProposedAction();
    emit mimeChanged(event->mimeData());
}

//This event handler is called if a drag is in progress, and when any of the following conditions occur:
//the cursor enters this widget, the cursor moves within this widget,
//or a modifier key is pressed on the keyboard while this widget has the focus.
void DragDropLabel::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

//This event handler is called when a drag is in progress and the mouse leaves this widget
void DragDropLabel::dragLeaveEvent(QDragLeaveEvent *event)
{
    clear();
}

// This event handler is called when the drag is dropped on this widget.
void DragDropLabel::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    if (mimeData->hasText())
    {
        setText(mimeData->text());
        setTextFormat(Qt::PlainText);
    }
    else if (mimeData->hasHtml())
    {
        setText(mimeData->html());
        setTextFormat(Qt::RichText);
    }
    else if (mimeData->hasImage())
    {
        setPixmap(qvariant_cast<QPixmap>(mimeData->imageData()));
    }
    else if (mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();
        QString text;
        for (int i = 0; i<urlList.size(); ++i)
        {
            text += urlList.at(i).path() + "----";
        }
        setText(text);
    }
    else
    {
        setText("Data cannot be displayed");
    }
}


void DragDropLabel::clear()
{
    setText("DROP SPACE");
    setBackgroundRole(QPalette::Dark);
    emit mimeChanged();
}
