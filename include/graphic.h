#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML/Graphics.hpp>
#include "grid.h"

using namespace std;

class Graphic{
    private:
        sf::RenderWindow window;
        float cellSize;
    public:
        Graphic(const Grid& grid);
        ~Graphic() = default;
        void render(const Grid& grid);
        float handleEvents(float simulationSpeed);
        bool isOpen();
};

#endif