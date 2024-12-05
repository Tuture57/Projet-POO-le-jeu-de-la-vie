#include "game.h"

#include <stdexcept>
#include <string>

using namespace std;

Game::Game(string filename, SimulationMode mode, int iteration) : mode(mode), maxIteration(iteration) {
    file = File(filename);
};

void Game::run(){
    if (mode == CONSOLE){
        for (int i = 0; i < maxIteration; i++){
            file.saveGrid(grid);
        }
    }else if (mode == GRAPHIC){
        render(grid);
        if 
        handleEvent();
    }else{
        throw runtime_error("Wrong mode");
    }
};

void Game::setSimulationSpeed(float speed){

}


int Game::getCurrentIteration(){

}


bool Game::isFinished(){

}