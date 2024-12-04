#ifndef GRID_H
#define GRID_H

#include <vector>
#include "cell.h"

class Grid{
    private:
        vector<vector<Cell>> cell;
        int width;
        int height;
    public:
        Grid();
        Grid(int w, int h);
        void update();
        vector<Cell> getCellNeighbors(int x, int y);

};

#endif