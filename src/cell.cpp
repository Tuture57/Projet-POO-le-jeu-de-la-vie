#include <stdexcept>
#include "cell.h"

using namespace std;

Cell::Cell() : isAlive(false), position(0, 0) {};

Cell::Cell(int x, int y, bool isAlive) : isAlive(isAlive), position(x, y) {};

void Cell::updateState(bool state){
    if (state == 0){
        isAlive = false;
    } else if (state == 1){
        isAlive = true;
    } else {
        throw invalid_argument("Impossible state for the Cell");
    }
}

 int Cell::getCellX() const{
    return position.getX();
}

int Cell::getCellY() const{
    return position.getY();
}

bool Cell::getNextState(vector<Cell> neighbors){
    int cpt = 0;
    for (int i = 0; i < neighbors.size(); i++){
        if (neighbors[i].getAlive()){
            cpt++;
        }
    }
    if (this->getAlive()){
        return (cpt == 2 || cpt == 3);
    } else {
        return cpt == 3;
    }
}

bool Cell::getAlive() const{
    return isAlive;
}

bool Cell::operator==(const Cell& c2) const{
    return (getCellX() == c2.getCellX() && getCellY() == c2.getCellY() && getAlive() == c2.getAlive());
}