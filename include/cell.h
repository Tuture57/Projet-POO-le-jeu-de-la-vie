#ifndef CELL_H
#define CELL_H

#include "position.h"
#include <vector>

class Cell {
    protected:
        Position position;
    public:
        Cell();
        Cell(int x, int y);
        virtual ~Cell() = default;

        int getCellX() const;
        int getCellY() const;

        virtual void updateState(bool state) = 0; 
        virtual bool getNextState(std::vector<Cell*> neighbors) = 0;
        virtual bool getAlive() const = 0;
        virtual bool operator==(const Cell& c2) const = 0;
};

#endif