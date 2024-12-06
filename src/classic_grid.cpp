#include "classic_grid.h"

using namespace std;

ClassicGrid::ClassicGrid() : width(0), height(0) {};

ClassicGrid::ClassicGrid(int w, int h, vector<vector<Cell>> cells) : cells(cells), width(w), height(h) {};

int ClassicGrid::getHeight() const{
    return height;
}

int ClassicGrid::getWidth() const{
    return width;
}

vector<vector<Cell>> ClassicGrid::getCells() const{
    return cells;
}

bool ClassicGrid::update(){
    vector<vector<Cell>> newCells;
    vector<Cell> line;
    vector<Cell> cellNeighbors;
    Cell cellNow;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cellNeighbors = getCellNeighbors(cells[i][j]);
            bool nextstate = cells[i][j].getNextState(cellNeighbors);
            cellNow = cells[i][j];
            cellNow.updateState(nextstate);
            line.push_back(cellNow);
        }
        newCells.push_back(line);
        line.clear();
    }
    if (cells == newCells){
        return 0;
    }else{
        cells = newCells;
        return 1;
    }
}

vector<Cell> ClassicGrid::getCellNeighbors(Cell cell){
    int x = cell.getCellX();
    int y = cell.getCellY();
    vector<Cell> stock;
    for (int i = max(0, y-1); i <= min(height-1, y+1); i++) {
        for (int j = max(0, x-1); j <= min(width-1, x+1); j++) {
            if (!(i == y && j == x)) {
                stock.push_back(cells[i][j]);
            }
        }
    }
    return stock;
}