#include "grid.h"

using namespace std;

Grid::Grid() : width(0), height(0) {};

Grid::Grid(int w, int h, vector<vector<Cell>> cells) : width(w), height(h), cells(cells) {};

int Grid::getHeight() const{
    return height;
}

int Grid::getWidth() const{
    return width;
}

vector<vector<Cell>> Grid::getCells() const{
    return cells;
}

bool Grid::update(){
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

vector<Cell> Grid::getCellNeighbors(Cell cell){
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