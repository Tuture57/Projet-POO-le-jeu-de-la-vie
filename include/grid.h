#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include <vector>

class Grid{
    public:
        virtual ~Grid() = default;
        virtual std::vector<std::vector<Cell>> getCells() const = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual bool update() = 0;
        virtual std::vector<Cell> getCellNeighbors(Cell cell) = 0;
};

#endif