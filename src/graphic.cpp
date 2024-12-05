#include "graphic.h"

Graphic::Graphic(const Grid& grid) : window(sf::VideoMode(800,800), "Game of Life") {
    float cellSizeX = 800.0f / grid.getWidth();
    float cellSizeY = 800.0f / grid.getHeight();
    cellSize = min(cellSizeX, cellSizeY);

    window.setFramerateLimit(60);
}

void Graphic::render(const Grid& grid) {
    window.clear(sf::Color::White);

    sf::RectangleShape line;
    line.setFillColor(sf::Color(200, 200, 200));  // Gris clair

    for (int x = 0; x <= grid.getWidth(); x++) {
        line.setSize(sf::Vector2f(1.0f, grid.getHeight() * cellSize));
        line.setPosition(x * cellSize, 0);
        window.draw(line);
    }

    for (int y = 0; y <= grid.getHeight(); y++) {
        line.setSize(sf::Vector2f(grid.getWidth() * cellSize, 1.0f));
        line.setPosition(0, y * cellSize);
        window.draw(line);
    }

    sf::RectangleShape aliveCell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    aliveCell.setFillColor(sf::Color::Black);

    vector<vector<Cell>> cells = grid.getCells();
    for (int y = 0; y < grid.getHeight(); y++) {
        for (int x = 0; x < grid.getWidth(); x++) {
            if (cells[y][x].getAlive()) {
                aliveCell.setPosition(x * cellSize, y * cellSize);
                window.draw(aliveCell);
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
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                simulationSpeed += 0.1f;
            }
            if (event.key.code == sf::Keyboard::Down) {
                simulationSpeed -= 0.1f;
            }
        }
    }
    return simulationSpeed;
 }

bool Graphic::isOpen() {
    return window.isOpen();
}