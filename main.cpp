#include "game.h"

using namespace std;

int main(int argc, char* argv[]) {
    string filename = argv[1];
    SimulationMode mode = static_cast<SimulationMode>(stoi(argv[2]));
    int iteration = stoi(argv[3]);
    Game game(filename, mode, iteration);
    game.run();
    return 0;
}