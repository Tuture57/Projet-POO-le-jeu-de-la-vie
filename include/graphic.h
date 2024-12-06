#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "classic_grid.h"
#include <SFML/Graphics.hpp>

class Graphic{
    private:
        sf::RenderWindow window;
        float cellSize;
        void initializeShapes();
        sf::RectangleShape gridLine;
        sf::RectangleShape aliveCell;
        void drawGrid(const ClassicGrid& grid);
        void drawCells(const ClassicGrid& grid);
    public:
        Graphic(const ClassicGrid& grid, unsigned int height, unsigned int width);
        ~Graphic() = default;
        void render(const ClassicGrid& grid);
        float handleEvents(float simulationSpeed);
        bool isOpen();
};

#endif