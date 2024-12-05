#ifndef GAME_H
#define GAME_H

using namespace std;

#include <string>
#include "grid.h"
#include "file.h"

enum SimulationMode{
    CONSOLE,
    GRAPHIC
};

class Game{
    private:
        Grid grid;
        SimulationMode mode;
        int maxIteration;
        float simulationSpeed;
        File file;
        Graphic graphic;
    public:
        Game();
        Game(string filename, SimulationMode mode, int iteration);
        void run();
        void setSimulationSpeed(float speed);
        int getCurrentIteration();
        bool isFinished();
};

#endif