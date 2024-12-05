#include "game.h"

#include <stdexcept>
#include <string>
#include <windows.h>
#include <thread>

using namespace std;

Game::Game(string filename, SimulationMode mode, int iteration) : mode(mode), maxIteration(iteration) {
    file = File(filename);
};

void Game::run(){
    if (mode == CONSOLE){
        for (int i = 0; i < maxIteration; i++){
            file.saveGrid(grid, i);
        }
    }else if (mode == GRAPHIC){
        thread thread_obj(RenderGrid());
        while(graphic.isOpen()){
            simulationSpeed = graphic.handleEvents();
        }
    }else{
        throw runtime_error("Wrong mode");
    }
};

void Game::RenderGrid(){
    while(graphic.isOpen()){
        grid.update();
        if (grid.update()){    
            graphic.render(grid);
            Sleep(simulationSpeed);
        }else{

        }
    }
}


void Game::setSimulationSpeed(float speed){
    
}

int Game::getCurrentIteration(){

}


bool Game::isFinished(){

}