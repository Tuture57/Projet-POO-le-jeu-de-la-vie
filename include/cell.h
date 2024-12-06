#ifndef CELL_H
#define CELL_H

#include "position.h"
#include <vector>

class Cell {
    private:
        bool isAlive;
        Position position;
    public:
        Cell();
        Cell(int x, int y, bool isAlive);
        ~Cell() = default;
        int getCellX() const;
        int getCellY() const;
        void updateState(bool state);
        bool getNextState(std::vector<Cell> neighbors);
        bool getAlive() const;
        bool operator==(const Cell& c2) const;
};

#endif