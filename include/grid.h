#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include <vector>
#include <memory>

class Grid {
    public:
        virtual ~Grid() = default;
        virtual const std::vector<std::vector<std::unique_ptr<Cell>>>& getCells() const = 0;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual bool update() = 0;
        virtual bool areEquals(const std::vector<std::vector<std::unique_ptr<Cell>>>& grid1, const std::vector<std::vector<std::unique_ptr<Cell>>>& grid2) const = 0;
        virtual std::vector<Cell*> getCellNeighbors(Cell& cell) = 0;
};

#endif