#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML/Graphics.hpp>

using namespace std, sf;

class graphic{
    private:
        RenderWindow window;
        Grid grid;
        float cellSize;
    public:
        graphic();
        graphic(Grid grid, float cellSize);
        ~graphic();
        void render();
        void handleEvents();
};

#endif