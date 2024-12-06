#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "grid.h"
#include <SFML/Graphics.hpp>

class Graphic{
    private:
        sf::RenderWindow window;
        float cellSize;
        void initializeShapes();
        sf::RectangleShape gridLine;
        sf::RectangleShape aliveCell;
        void drawGrid(const Grid& grid);
        void drawCells(const Grid& grid);
    public:
        Graphic(const Grid& grid, unsigned int height, unsigned int width);
        ~Graphic() = default;
        void render(const Grid& grid);
        float handleEvents(float simulationSpeed);
        bool isOpen();
};

#endif