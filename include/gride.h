#ifndef GRID_H
#define GRID_H

#include <vector>
#include "cell.h"

class Grid : public Cell{
    private:
        Position position;
        int width;
        int height;
    public:
        Grid(int w, int h);
        
};

#endif //GRID_H