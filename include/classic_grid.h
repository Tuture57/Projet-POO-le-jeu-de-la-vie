#ifndef CLASSIC_GRID_H
#define CLASSIC_GRID_H

#include "grid.h"
#include "cell.h"
#include <vector>
#include <memory>

class ClassicGrid : public Grid {
    private:
        std::vector<std::vector<std::unique_ptr<Cell>>> cells;
        int width;
        int height;
    public:
        ClassicGrid();
        ClassicGrid(int w, int h, std::vector<std::vector<std::unique_ptr<Cell>>> cells);
        const std::vector<std::vector<std::unique_ptr<Cell>>>& getCells() const override;
        int getWidth() const override;
        int getHeight() const override;
        bool update() override;
        std::vector<Cell*> getCellNeighbors(Cell& cell) override;
};

#endif