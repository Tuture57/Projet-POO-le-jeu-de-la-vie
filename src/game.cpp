#include "game.h"

#include <stdexcept>
#include <chrono>
#include <thread>

using namespace std;

atomic<bool> running(true);

Game::Game(string filename, SimulationMode mode, int iteration) : mode(mode), graphic(nullptr),  maxIteration(iteration){
    file = File(filename);
    grid = file.loadGrid();
};

Game::~Game(){
    if (graphic != nullptr){
        delete graphic;
    }
};

void Game::run(){
    if (mode == CONSOLE) {
        for (int i = 0; i < maxIteration; i++){
            if (grid.update()) {
                file.saveGrid(grid, i);
            } else {
                break;
            }
        }
    } else if (mode == GRAPHIC) {
        graphic = new Graphic(grid, 800, 800);
        simulationSpeed = 1.0f;

        startLogicThread();
        
        while(graphic->isOpen()){
            float newSpeed = graphic->handleEvents(simulationSpeed.load());
            simulationSpeed.store(newSpeed); 
            graphic->render(grid);
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
        if (grid.update()){    
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(simulationSpeed.load() * 1000)));
        }else{
            stopLogicThread();
        }
    }
}