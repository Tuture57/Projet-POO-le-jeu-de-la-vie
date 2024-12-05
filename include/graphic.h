#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML/Graphics.hpp>

using namespace std;

class Graphic{
    private:
        sf::RenderWindow window;
        float cellSize;
    public:
        Graphic();
        Graphic(Grid grid, float cellSize);
        ~Graphic() = default;
        void render(Grid grid);
        float handleEvents(float simulationSpeed);
        bool isOpen();
};

#endif