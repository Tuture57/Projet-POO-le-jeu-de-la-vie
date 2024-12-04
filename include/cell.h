#ifndef CELL_H
#define CELL_H

#include <vector>
#include "position.h"

class Cell : public Position{
    private:
        bool isAlive;
        Position position;
    public:
        Cell();
        Cell(int x, int y);
        void updateState(bool state);
        bool getNextState(vector<Cell> neighbors);
        bool isAlive();
};

#endif