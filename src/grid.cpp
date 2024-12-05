#include "grid.h"

using namespace std;

Grid::Grid(int w, int h, vector<vector<Cell>> cells) : width(w), height(h), cells(cells) {};

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
    vector<Cell> stock;
    stock.push_back(cells[x-1][y-1]);
    stock.push_back(cells[x][y-1]);
    stock.push_back(cells[x+1][y-1]);
    stock.push_back(cells[x-1][y]);
    stock.push_back(cells[x+1][y]);
    stock.push_back(cells[x-1][y+1]);
    stock.push_back(cells[x][y+1]);
    stock.push_back(cells[x+1][y+1]);
}