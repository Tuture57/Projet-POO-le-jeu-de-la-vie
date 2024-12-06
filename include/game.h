#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "file.h"
#include "graphic.h"
#include <string>
#include <atomic>

enum SimulationMode{
    CONSOLE,
    GRAPHIC
};

class Game{
    private:
        Grid grid;
        SimulationMode mode;
        File file;
        Graphic* graphic;
        int maxIteration;
        std::atomic<float> simulationSpeed;
    public:
        Game();
        Game(std::string filename, SimulationMode mode, int iteration);
        ~Game();
        void run();
        void startLogicThread();
        void stopLogicThread();
        void CalculLogique(); 
};

#endif