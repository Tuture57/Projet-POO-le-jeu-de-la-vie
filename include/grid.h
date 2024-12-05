#ifndef GRID_H
#define GRID_H

#include <vector>
#include "cell.h"

class Grid{
    private:
        vector<vector<Cell>> cells;
        int width;
        int height;
    public:
        Grid();
        Grid(int w, int h, vector<vector<Cell>> cells);
        int getWidth();
        int getHeight();
        void update();
        vector<Cell> getCellNeighbors(Cell cellNeighbors);
};

#endif