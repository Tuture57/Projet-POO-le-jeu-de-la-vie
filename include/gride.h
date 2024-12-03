#ifndef GRID_H
#define GRID_H

#include <vector>
#include "cell.h"

class Grid : public Cell{
    private:
        Position position;
        int width;
        int height;
    public:
        Cell(int x, int y);
        void updateState(bool state);
        bool getNextState(vector<Cell> neighbors);
        bool isAlive();
};

#endif //GRID_H