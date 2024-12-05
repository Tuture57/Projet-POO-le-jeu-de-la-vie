#ifndef CELL_H
#define CELL_H

#include <vector>
#include "position.h"

using namespace std;

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
        bool getNextState(vector<Cell> neighbors);
        bool getAlive() const;
        bool operator==(const Cell& c2) const;
};

#endif