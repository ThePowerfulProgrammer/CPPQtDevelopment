#include "widget.h"
#include "ui_widget.h"
#include <QMimeData>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    dragDropLabel = new DragDropLabel(this);

    // S & S
    connect(dragDropLabel, SIGNAL(mimeChanged(const QMimeData*)), this, SLOT(mimeChanged(const QMimeData*)));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clear()));

    ui->labelLayout->addWidget(dragDropLabel);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mimeChanged(const QMimeData *mimeData)
{
    ui->textEdit->clear();
    if (!mimeData)
    {
        return;
    }

    QStringList formats = mimeData->formats();

    for (int i=0 ; i < formats.size(); i++)
    {
        QString text;
        if (formats[i] == QString("text/plain"))
        {
            text = mimeData->text().simplified();
        }
        else if (formats[i] == QString("text/html"))
        {
            text = mimeData->html().simplified();
        }
        else if (formats[i] == QString("text/uri-list"))
        {
            QList<QUrl> urlList = mimeData->urls();
            for (int i=0 ;i < urlList.size(); ++i)
            {
                text.append(urlList.at(i).toString() + " -/- ");
            }
        }
        else
        {
            QByteArray data = mimeData->data(formats[i]);
            for (int i = 0; i < data.size(); ++i)
            {
                text.append(QString("%1").arg(uchar(data[i])));
            }
        }

        QString dataString = QString("%1 | Format : %2 \n   | Data : %2 \n--------")
                .arg(i)
                .arg(formats[i])
                .arg(text);

        ui->textEdit->append(dataString);
    }


}


void Widget::clear()
{
    ui->textEdit->clear();
}
