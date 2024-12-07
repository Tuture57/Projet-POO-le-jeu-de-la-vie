#include "classic_grid.h"
#include "classic_cell.h"

using namespace std;

ClassicGrid::ClassicGrid() : width(0), height(0) {}

ClassicGrid::ClassicGrid(int w, int h, std::vector<std::vector<std::unique_ptr<Cell>>> c)
    : cells(std::move(c)), width(w), height(h) {}

int ClassicGrid::getHeight() const{
    return height;
}

int ClassicGrid::getWidth() const{
    return width;
}

const vector<vector<std::unique_ptr<Cell>>>& ClassicGrid::getCells() const {
    return cells;
}

bool ClassicGrid::update() {
    std::vector<std::vector<std::unique_ptr<Cell>>> newCells;
    newCells.reserve(height);

    for (int i = 0; i < height; i++) {
        std::vector<std::unique_ptr<Cell>> newRow;
        newRow.reserve(width);
        for (int j = 0; j < width; j++) {
            auto cellNeighbors = getCellNeighbors(*cells[i][j]);
            bool nextstate = cells[i][j]->getNextState(cellNeighbors);
            newRow.push_back(std::make_unique<ClassicCell>(cells[i][j]->getCellX(), cells[i][j]->getCellY(), nextstate));
        }
        newCells.push_back(std::move(newRow));
    }
    if (cells == newCells){
        return 0;
    }else{
        cells = std::move(newCells);
        return 1;
    }
}

vector<Cell*> ClassicGrid::getCellNeighbors(Cell& cell){
    int x = cell.getCellX();
    int y = cell.getCellY();
    vector<Cell*> stock;
    for (int i = max(0, y-1); i <= min(height-1, y+1); i++) {
        for (int j = max(0, x-1); j <= min(width-1, x+1); j++) {
            if (!(i == y && j == x)) {
                stock.push_back(cells[i][j].get());
            }
        }
    }
    return stock;
}