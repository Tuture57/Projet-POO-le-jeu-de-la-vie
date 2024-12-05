#include "graphic.h"

Graphic::Graphic() : window(sf::VideoMode(800, 850), "Game of Life"), cellSize(10.0f) {}

void Graphic::render(const Grid& grid) {
    vector<vector<Cell>> cells = grid.getCells();
    window.clear();
    sf::RectangleShape aliveCell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int i = 0; i < grid.getHeight(); ++i) {
        for (int j = 0; j < grid.getWidth(); ++j) {
            if (cells[i][j].getAlive()) {
                aliveCell.setPosition(j * cellSize, i * cellSize);
                window.draw(aliveCell);
            } else {
                throw runtime_error("Cell is neither alive nor dead");
            }
        }
    }
    window.display();
}

float Graphic::handleEvents(float simulationSpeed) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.key.code == sf::Keyboard::Up) {
            simulationSpeed -= 0.1;
        }
        if (event.key.code == sf::Keyboard::Down) {
            simulationSpeed += 0.1;
        }
    }
    return simulationSpeed;
 }

bool Graphic::isOpen() {
    return window.isOpen();
}