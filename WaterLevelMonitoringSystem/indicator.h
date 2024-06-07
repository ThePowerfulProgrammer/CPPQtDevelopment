#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = 0);
    QSize sizeHint() const; // sets size

signals:

public slots:

private:

protected:
    // default widget drawing
    void paintEvent(QPaintEvent *event);

private:

    bool greenActive;
    bool redActive;
    bool yellowActive;
};

#endif // INDICATOR_H
