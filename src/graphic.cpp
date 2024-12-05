#include "graphic.h"

Graphic::Graphic() : window.create(VideoMode(800, 600), "Game of Life") {}

Graphic::Graphic(Grid grid, float cellSize) : window.create(800, 600), "Game of Life"), grid(grid), cellSize(cellSize) {}

void Graphic::render(Grid grid) {
    int x, y;
    
    window.clear();
    RectangleShape cell(Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < grid.getWidth(); ++x) {
        for (y = 0; y < grid.getHeight(); ++y) {
            if (grid.getCells(x, y).isAlive()) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}