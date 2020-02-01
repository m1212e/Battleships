#include "board.h"

#include <QGridLayout>
#include <QSequentialAnimationGroup>
#include <QGraphicsOpacityEffect>

Board::Board(int width, int height, QWidget *parent) : QWidget(parent), width(width), height(height)
{
    setParent(parent);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            BoardUnit *bu = new BoardUnit(x, y, this);
            mainLayout->addWidget(bu, y, x);
            bu->fadeIn();
        }
    }

    setLayout(mainLayout);
}
