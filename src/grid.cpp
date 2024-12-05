#include "grid.h"

using namespace std;

Grid::Grid(int w, int h, vector<vector<Cell>> cell) : width(w), height(h), cell(cell) {};

int Grid::getHeight(){
    return height;
}

int Grid::getWidth(){
    return width;
}

void Grid::update(){

}

vector<Cell> Grid::getCellNeighbors(Cell cellNeighbors){
    int x = cellNeighbors.getCellX();
    int y = cellNeighbors.getCellY();
    vector<Cell> stock = cell[x-1][y-1];
}