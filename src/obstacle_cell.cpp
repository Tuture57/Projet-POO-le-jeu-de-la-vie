#include "obstacle_cell.h"

ObstacleCell::ObstacleCell() : Cell(), isAlive(false) {}

ObstacleCell::ObstacleCell(int x, int y, bool alive) : Cell(x, y), isAlive(alive) {}

std::unique_ptr<Cell> ObstacleCell::clone(bool state) const {
    return std::make_unique<ObstacleCell>(getCellX(), getCellY(), state);
}

void ObstacleCell::updateState(bool state) {
    isAlive = state;
}

bool ObstacleCell::getNextState(std::vector<Cell*> neighbors) {
    return isAlive;
}

bool ObstacleCell::getAlive() const {
    return isAlive;
}

bool ObstacleCell::operator==(const Cell& c2) const {
    return (getCellX() == c2.getCellX() && getCellY() == c2.getCellY() && getAlive() == c2.getAlive());
}