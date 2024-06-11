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
    void emitNormal();
    void emitWarning();
    void emitDanger();

public slots:
    void increasingWaterLevel();

protected:
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    int waterLevel;
    QTimer *timer;
};

#endif // WATERTANK_H
