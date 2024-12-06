#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "classic_grid.h"

class Graphic{
    public:
        virtual ~Graphic() = default;
        virtual void render(const ClassicGrid& grid) = 0;
        virtual float handleEvents(float simulationSpeed) = 0;
        virtual bool isOpen() = 0;
};

#endif