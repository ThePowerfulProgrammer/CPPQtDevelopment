#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QTimer>

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = 0);
    QSize sizeHint() const; // sets size

signals:

public slots:
    void colorToggle();

    void activateGo();
    void activateWarning();
    void activateDanger();

private:

protected:
    // default widget drawing
    void paintEvent(QPaintEvent *event);

private:
    bool greenActive;
    bool redActive;
    bool yellowActive;
    bool lightsOn;
    QTimer *timer;
};

#endif // INDICATOR_H
