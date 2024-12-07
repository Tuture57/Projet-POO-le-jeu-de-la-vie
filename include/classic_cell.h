#ifndef CLASSIC_CELL_H
#define CLASSIC_CELL_H

#include "cell.h"

class ClassicCell : public Cell {
    private:
        bool isAlive;
    public:
        ClassicCell();
        ClassicCell(int x, int y, bool alive); // Ensure this declaration is correct

        void updateState(bool state) override;
        bool getNextState(std::vector<Cell*> neighbors) override;
        bool getAlive() const override;
        bool operator==(const Cell& c2) const override;
};

#endif