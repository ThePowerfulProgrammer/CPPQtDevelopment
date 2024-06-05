#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include <QWidget>
#include <QDate>
#include <QTime>
#include <QLabel>
#include <QTimer>

class DateTimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DateTimeWidget(QWidget *parent = 0);

signals:

public slots:
    void updateDateTime();

private:
    QTimer *timer;

    QString dateString;
    QLabel *dateLabel;

    QString timeString;
    QLabel *timeLabel;

};

#endif // DATETIMEWIDGET_H
