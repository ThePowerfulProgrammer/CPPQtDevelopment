#include "datetimewidget.h"
#include <QVBoxLayout>

DateTimeWidget::DateTimeWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mainLayout =  new QVBoxLayout(this);
    QFont mFont("Oswald", 22, QFont::Bold);
    QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    dateString = QDate::currentDate().toString(Qt::TextDate);
    dateLabel = new QLabel(this);
    dateLabel->setText(dateString);
    dateLabel->setFont(mFont);
    dateLabel->setAlignment(Qt::AlignCenter);


    timeString = QTime::currentTime().toString();
    timeLabel = new QLabel(this);
    timeLabel->setText(timeString);
    timeLabel->setFont(mFont);
    timeLabel->setAlignment(Qt::AlignCenter);
    QString css = QString("background-color : #00eff9; color : #fffff1");
    timeLabel->setStyleSheet(css);

    // timer
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDateTime()));
    timer->start();


    setSizePolicy(policy);

    mainLayout->addWidget(dateLabel);
    mainLayout->addWidget(timeLabel);

    setLayout(mainLayout);
    setWindowTitle("Date Time Widget");

}

void DateTimeWidget::updateDateTime()
{
    timeString = QTime::currentTime().toString();
    timeLabel->setText(timeString);

    dateString = QDate::currentDate().toString(Qt::TextDate);
    dateLabel->setText(dateString);
}




