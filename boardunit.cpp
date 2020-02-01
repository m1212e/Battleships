#include "boardunit.h"

#include <iostream>

BoardUnit::BoardUnit(int x, int y, QWidget *parent) : AnimatedQPushButton(parent), x(x), y(y)
{
    setParent(parent);
    setText("");
    setMinimumWidth(60);
    setMinimumHeight(55);
}

void BoardUnit::mousePressEvent(QMouseEvent *e)
{
}
