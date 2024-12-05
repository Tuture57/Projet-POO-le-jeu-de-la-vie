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
        int getCellX();
        int getCellY();
        void updateState(bool state);
        bool getNextState(vector<Cell> neighbors);
        bool getAlive();
};

#endif