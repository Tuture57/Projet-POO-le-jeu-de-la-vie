#include "game.h"

#include <stdexcept>
#include <string>
#include <windows.h>
#include <thread>
#include <atomic>

using namespace std;

Game::Game(string filename, SimulationMode mode, int iteration) : mode(mode), maxIteration(iteration) {
    file = File(filename);
};

atomic<bool> running(true);

void Game::run(){
    if (mode == CONSOLE) {
        for (int i = 0; i < maxIteration; i++){
            file.saveGrid(grid, i);
        }
    } else if (mode == GRAPHIC) {
        startRenderThread();
        while(graphic.isOpen()){
            simulationSpeed = graphic.handleEvents();
        }
    } else {
        throw runtime_error("Wrong mode");
    }
};

void Game::setSimulationSpeed(float speed){
    
}

void Game::startRenderThread() {
    thread renderThread(RenderGrid);
    renderThread.detach();
}

void Game::stopRenderThread() {
    running = false;
}

void Game::RenderGrid(){
    while(graphic.isOpen()){
        grid.update();
        if (grid.update()){    
            graphic.render(grid);
            Sleep(simulationSpeed);
        }else{
            stopRenderThread();
        }
    }
}

void Game::setSimulationSpeed(float speed){
    
}

int Game::getCurrentIteration(){

}
