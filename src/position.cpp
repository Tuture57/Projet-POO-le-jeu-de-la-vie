#include "position.h"

using namespace std;

Position::Position(int x, int y) : x(x), y(y) {};

int Position::getX(){
    return x;
}

int Position::getY(){
    return y;
}