#include "game.h"
#include "graphic_sfml.h"

#include <stdexcept>
#include <chrono>
#include <thread>

using namespace std;

atomic<bool> running(true);

Game::Game() : mode(CONSOLE), maxIteration(0) {}

Game::Game(string filename, SimulationMode mode) : mode(mode), maxIteration(-1) {
    file = std::make_unique<File>(filename);
    grid = file->loadGrid(); // Use the unique pointer directly
}

Game::Game(string filename, SimulationMode mode, int iteration) : mode(mode), maxIteration(iteration) {
    file = std::make_unique<File>(filename);
    grid = file->loadGrid(); // Use the unique pointer directly
}

Game::~Game() = default;

void Game::run() {
    if (mode == CONSOLE) {
        for (int i = 0; i < maxIteration; i++) {
            if (grid->update()) {
                file->saveGrid(*grid, i);
            } else {
                break;
            }
        }
    } else if (mode == GRAPHIC) {
        graphic = std::make_unique<GraphicSFML>(*grid, 800, 800);
        simulationSpeed = 1.0f;

        startLogicThread();
        
        while(graphic->isOpen()){
            float newSpeed = graphic->handleEvents(simulationSpeed.load());
            simulationSpeed.store(newSpeed); 
            graphic->render(*grid);
        }
    } else {
        throw runtime_error("Wrong mode");
    }
}

void Game::startLogicThread() {
    thread renderThread = thread(&Game::CalculLogique, this);
    renderThread.detach();
}

void Game::stopLogicThread() {
    running.store(false);
}

void Game::CalculLogique() {
    while(running.load()){
        if (grid->update()){    
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(simulationSpeed.load() * 1000)));
        }else{
            stopLogicThread();
        }
    }
}