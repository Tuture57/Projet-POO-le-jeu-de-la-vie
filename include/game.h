#ifndef GAME_H
#define GAME_H

#include "classic_grid.h"
#include "file.h"
#include "graphic.h"
#include <string>
#include <atomic>
#include <memory>

enum SimulationMode{
    CONSOLE,
    GRAPHIC
};

class Game{
    private:
        std::unique_ptr<ClassicGrid> grid;
        SimulationMode mode;
        std::unique_ptr<File> file;
        std::unique_ptr<Graphic> graphic;
        int maxIteration;
        std::atomic<float> simulationSpeed;
    public:
        Game();
        Game(std::string filename, SimulationMode mode);
        Game(std::string filename, SimulationMode mode, int iteration);
        ~Game();
        void run();
        void startLogicThread();
        void stopLogicThread();
        void CalculLogique(); 
};

#endif