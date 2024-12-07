#ifndef OBS_CELL_H
#define OBS_CELL_H

#include "cell.h"

class ObstacleCell : public Cell {
    private:
        bool isAlive;
    public:
        ObstacleCell();
        ObstacleCell(int x, int y, bool alive);

        std::unique_ptr<Cell> clone(bool state) const override;
        void updateState(bool state) override;
        bool getNextState(std::vector<Cell*> neighbors) override;
        bool getAlive() const override;
        bool operator==(const Cell& c2) const override;
};

#endif