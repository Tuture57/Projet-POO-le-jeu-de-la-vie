#include "grid.h"

//width = j = x
//height = i = y

using namespace std;

Grid::Grid(int w, int h, vector<vector<Cell>> cells) : width(w), height(h), cells(cells) {};

int Grid::getHeight(){
    return height;
}

int Grid::getWidth(){
    return width;
}

vector<vector<Cell>> Grid::getCells(){
    return cells;
}

void Grid::update(){
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
    cells = newCells;
}

vector<Cell> Grid::getCellNeighbors(Cell cell){
    int x = cell.getCellX();
    int y = cell.getCellY();
    vector<Cell> stock;
    for (int i = y-1; i < y+2; i++){
        if (i < 0 || i > height){
            i++;
        }else{
            for (int j = x-1; j < x+2; j++){
                if (j < 0 || j > width){
                    j++;
                }else{
                    if (i == x && j == y){
                        i++;
                    }else{
                        stock.push_back(cells[i][j]);
                    }
                }
            }
        }
    }
    return stock;
}