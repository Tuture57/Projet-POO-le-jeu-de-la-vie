#ifndef GAME_H
#define GAME_H

using namespace std;

#include <string>
#include "grid.h"
#include "file.h"
#include "graphic.h"

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
        void startRenderThread();
        void stopRenderThread();
        void RenderGrid();
};

#endif