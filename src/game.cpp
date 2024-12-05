#include "game.h"

#include <stdexcept>
#include <chrono>
#include <thread>

using namespace std;

atomic<bool> running(true);

Game::Game(string filename, SimulationMode mode, int iteration) : mode(mode), maxIteration(iteration), graphic(nullptr){
    file = File(filename);
    grid = file.loadGrid();
};

Game::~Game(){
    if (graphic != nullptr){
        delete graphic;
    }
};

void Game::startRenderThread() {
    thread renderThread = thread(&Game::RenderGrid, this);
    renderThread.detach();
}

void Game::stopRenderThread() {
    running.store(false);
}

void Game::RenderGrid(){
    while(graphic->isOpen()){
        if (grid.update()){    
            graphic->render(grid);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(simulationSpeed.load() * 1000)));
        }else{
            stopRenderThread();
        }
    }
}

void Game::run(){
    if (mode == CONSOLE) {
        for (int i = 0; i < maxIteration; i++){
            grid.update();
            file.saveGrid(grid, i);
        }
    } else if (mode == GRAPHIC) {
        graphic = new Graphic();
        simulationSpeed = 1.0f;

        startRenderThread();
        
        while(graphic->isOpen()){
            float newSpeed = graphic->handleEvents(simulationSpeed.load());
            simulationSpeed.store(newSpeed);
        }
    } else {
        throw runtime_error("Wrong mode");
    }
};