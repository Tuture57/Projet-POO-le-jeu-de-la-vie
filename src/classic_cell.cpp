#include <stdexcept>
#include "classic_cell.h"

using namespace std;

ClassicCell::ClassicCell() : Cell(0, 0), isAlive(false) {}

ClassicCell::ClassicCell(int x, int y, bool isAlive) : Cell(x, y), isAlive(isAlive) {} // Ensure this definition is correct

void ClassicCell::updateState(bool state){
    if (state == 0){
        isAlive = false;
    } else if (state == 1){
        isAlive = true;
    } else {
        throw invalid_argument("Impossible state for the Cell");
    }
}

bool ClassicCell::getNextState(vector<Cell*> neighbors){
    int cpt = 0;
    for (int i = 0; i < neighbors.size(); i++){
        if (neighbors[i]->getAlive()){
            cpt++;
        }
    }
    if (this->getAlive()){
        return (cpt == 2 || cpt == 3);
    } else {
        return cpt == 3;
    }
}

bool ClassicCell::getAlive() const{
    return isAlive;
}

bool ClassicCell::operator==(const Cell& c2) const{
    return (getCellX() == c2.getCellX() && getCellY() == c2.getCellY() && getAlive() == c2.getAlive());
}