#include "cell.h"

Cell::Cell() : position(0, 0) {};

Cell::Cell(int x, int y) : position(x, y) {};

int Cell::getCellX() const{
    return position.getX();
}

int Cell::getCellY() const{
    return position.getY();
}