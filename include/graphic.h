#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML/Graphics.hpp>

using namespace std, sf;

class Graphic{
    private:
        RenderWindow window;
        float cellSize;
    public:
        Graphic();
        Graphic(Grid grid, float cellSize);
        ~graphic();
        void render(Grid grid);
        int handleEvents(float simulationSpeed);
};

#endif