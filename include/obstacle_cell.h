#ifndef OBS_CELL_H
#define OBS_CELL_H

#include "cell.h"

class ObstacleCell : public Cell {
    private:
        bool obstacle;
    public:
        ObstacleCell(int x, int y);
        
        void updateState(bool) override;
        bool getNextState(std::vector<Cell*>) override;
        bool getAlive() const override;
        bool operator==(const Cell& c2) const override;
};

#endif