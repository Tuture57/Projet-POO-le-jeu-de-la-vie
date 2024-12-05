#include "game.h"

#include <stdexcept>
#include <string>

using namespace std;

Game::Game(string filename, SimulationMode mode, int iteration) : mode(mode), maxIteration(iteration) {
    file = File(filename);
};

void Game::run(){
    if (mode == CONSOLE){
        for (int i = 0; i < )
    }else if (mode == GRAPHIC){

    }else{
        throw invalid_argument("Wrong mode");
    }

}