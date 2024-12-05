#include "graphic.h"

Graphic::Graphic() : window.create(VideoMode(800, 600), "Game of Life") {}

Graphic::Graphic(Grid grid, float cellSize) : window.create(800, 600), "Game of Life"), grid(grid), cellSize(10.0f) {}

void Graphic::render(Grid grid) {
    vector<vector<Cell>> cells = grid.getCells();
    window.clear();
    RectangleShape aliveCell(Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    aliveCell.setFillColor(Color::Black);
    RectangleShape deadCell(Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    deadCell.setFillColor(Color::Transparent);
    deadcell.setOutlineColor(Color::Black);
    deadcell.setOutlineThickness(1.0f);

    for (int i = 0; i < grid.getHeight(); ++i) {
        for (int j = 0; j < grid.getWidth(); ++j) {
            if (cells[i][j].isAlive()) {
                aliveCell.setPosition(j * cellSize, i * cellSize);
                window.draw(aliveCell);
            } else if (cells[i][j].isDead()) {
                deadCell.setPosition(j * cellSize, i * cellSize);
                window.draw(deadCell);
            } else {
                throw runtime_error("Cell is neither alive nor dead");
            }
        }
    }
    window.display();
}

int Graphic::handleEvents(float simulationSpeed) {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            return -1;
        }
        if (event.key.code == Keyboard::Up) {
            simulationSpeed -= 0.1;
        }
        if (event.key.code == Keyboard::Down) {
            simulationSpeed += 0.1;
        }
    }
    return simulationSpeed;
 }