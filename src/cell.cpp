#include <stdexcept>
#include "cell.h"

using namespace std;

Cell::Cell() : position(0, 0), isAlive(false) {};

Cell::Cell(int x, int y, bool isAlive) : position(x, y), isAlive(isAlive) {};

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
    int x = position.getX();
    int y = position.getY();
    int cpt;
    for (int i = 0; i < neighbors.size(); i++){
        if (neighbors[i].getAlive()){
            cpt++;
        }
    }
    if (this->getAlive()){
        if (cpt == 2 || cpt == 3){
            return true;
        } else if(cpt != 2 || cpt != 3){
            return false;
        }else{
            throw invalid_argument("This state doesn't exist");
        }
    }else{
        if (cpt == 2){
            return true;
        } else if(cpt != 3){
            return false;
        }else{
            throw invalid_argument("This state doesn't exist");
        }
    }
}

bool Cell::getAlive() const{
    return isAlive;
}

bool Cell::operator==(const Cell& c2) const{
    return (getCellX() == c2.getCellX() && getCellY() == c2.getCellY() && getAlive() == c2.getAlive());
}