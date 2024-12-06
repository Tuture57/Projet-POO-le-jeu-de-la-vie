#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include <vector>

class Grid{
    private:
        std::vector<std::vector<Cell>> cells;
        int width;
        int height;
    public:
        Grid();
        Grid(int w, int h, std::vector<std::vector<Cell>> cells);
        std::vector<std::vector<Cell>> getCells() const;
        int getWidth() const;
        int getHeight() const;
        bool update();
        std::vector<Cell> getCellNeighbors(Cell cell);
};

#endif