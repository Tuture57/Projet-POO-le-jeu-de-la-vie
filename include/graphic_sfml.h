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
        void drawGrid(const ClassicGrid& grid);
        void drawCells(const ClassicGrid& grid);
    public:
        GraphicSFML(const ClassicGrid& grid, unsigned int height, unsigned int width);
        ~GraphicSFML() = default;
        void render(const ClassicGrid& grid) override;
        float handleEvents(float simulationSpeed) override;
        bool isOpen() override;
};

#endif