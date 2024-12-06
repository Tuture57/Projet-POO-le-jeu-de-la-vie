#ifndef CLASSIC_GRID_H
#define CLASSIC_GRID_H

#include "grid.h"
#include "cell.h"
#include <vector>

class ClassicGrid : public Grid {
    private:
        std::vector<std::vector<Cell>> cells;
        int width;
        int height;
    public:
        ClassicGrid();
        ClassicGrid(int w, int h, std::vector<std::vector<Cell>> cells);
        std::vector<std::vector<Cell>> getCells() const override;
        int getWidth() const override;
        int getHeight() const override;
        bool update() override;
        std::vector<Cell> getCellNeighbors(Cell cell) override;
};

#endif