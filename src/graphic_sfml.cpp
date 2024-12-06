#include "graphic_sfml.h"


using namespace std;

GraphicSFML::GraphicSFML(const ClassicGrid& grid, unsigned int height, unsigned int width) {
    cellSize = min(width / grid.getWidth(), height / grid.getHeight());
    window.create(sf::VideoMode(cellSize * grid.getWidth(), cellSize * grid.getHeight()), "Game of Life");
    initializeShapes();
    window.setFramerateLimit(60);
}

void GraphicSFML::initializeShapes() {
    gridLine.setFillColor(sf::Color(200, 200, 200));
    aliveCell.setSize(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    aliveCell.setFillColor(sf::Color::Black);
}

void GraphicSFML::drawGrid(const ClassicGrid& grid) {
    for (int x = 0; x <= grid.getWidth(); x++) {
        gridLine.setSize(sf::Vector2f(1.0f, grid.getHeight() * cellSize));
        gridLine.setPosition(x * cellSize, 0);
        window.draw(gridLine);
    }

    for (int y = 0; y <= grid.getHeight(); y++) {
        gridLine.setSize(sf::Vector2f(grid.getWidth() * cellSize, 1.0f));
        gridLine.setPosition(0, y * cellSize);
        window.draw(gridLine);
    }
}

void GraphicSFML::drawCells(const ClassicGrid& grid) {
    vector<vector<Cell>> cells = grid.getCells();
    for (int y = 0; y < grid.getHeight(); y++) {
        for (int x = 0; x < grid.getWidth(); x++) {
            if (cells[y][x].getAlive()) {
                aliveCell.setPosition(x * cellSize, y * cellSize);
                window.draw(aliveCell);
            }
        }
    }
}

void GraphicSFML::render(const ClassicGrid& grid) {
    window.clear(sf::Color::White);
    drawGrid(grid);
    drawCells(grid);
    window.display();
}

float GraphicSFML::handleEvents(float simulationSpeed) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            } if (event.key.code == sf::Keyboard::Up) {
                simulationSpeed -= 0.1f;
            } if (event.key.code == sf::Keyboard::Down) {
                simulationSpeed += 0.1f;
            }
        }
    }
    return simulationSpeed;
}

bool GraphicSFML::isOpen() {
    return window.isOpen();
}