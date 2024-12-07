#include "obstacle_cell.h"

void ObstacleCell::updateState(bool) {}

bool ObstacleCell::getNextState(std::vector<Cell*>) {
    return true;
}

bool ObstacleCell::getAlive() const {
    return true;
}

bool ObstacleCell::operator==(const Cell& c2) const {
    return (getCellX() == c2.getCellX() && getCellY() == c2.getCellY());
}