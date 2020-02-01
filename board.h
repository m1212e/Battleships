#ifndef BOARD_H
#define BOARD_H


#include "boardunit.h"

class Board: public QWidget
{

    Q_OBJECT

public:
    explicit Board(int width, int height, QWidget *parent = nullptr);

private:
    int width;
    int height;
};

#endif // BOARD_H
