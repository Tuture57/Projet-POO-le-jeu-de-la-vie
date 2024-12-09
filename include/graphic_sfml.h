#ifndef GRAPHIC_SFML_H
#define GRAPHIC_SFML_H

#include "classic_grid.h"
#include "graphic.h"
#include <SFML/Graphics.hpp>

class GraphicSFML : public Graphic {
    private:
        sf::RenderWindow window;
        float cellSize;
        void initializeShapes();
        sf::RectangleShape gridLine;
        sf::RectangleShape aliveCell;
        void drawGrid(const Grid& grid);
        void drawCells(const Grid& grid);
    public:
        GraphicSFML(const Grid& grid, unsigned int height, unsigned int width);
        ~GraphicSFML() = default;
        void render(const Grid& grid) override;
        float handleEvents(float simulationSpeed) override;
        bool isOpen() override;
};

#endif