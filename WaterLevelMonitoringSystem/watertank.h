#ifndef WATERTANK_H
#define WATERTANK_H

#include <QWidget>
#include <QTimer>


class WaterTank : public QWidget
{
    Q_OBJECT
public:
    explicit WaterTank(QWidget *parent = 0);
    QSize sizeHint() const;
signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);


private:
    int waterLevel;
    QTimer *timer;
};

#endif // WATERTANK_H
