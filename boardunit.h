#ifndef BOARDUNIT_H
#define BOARDUNIT_H


#include "animatedqpushbutton.h"

class BoardUnit : public AnimatedQPushButton
{
    Q_OBJECT

public:
    explicit BoardUnit(int x, int y, QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *e);

private:
    int x;
    int y;
};

#endif // BOARDUNIT_H
