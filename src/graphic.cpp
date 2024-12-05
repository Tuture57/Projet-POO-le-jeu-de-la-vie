#include "graphic.h"

graphic::graphic() {
    window.create(VideoMode(grid.getWidth() * cellSize, grid.getHeight() * cellSize), "Game of Life");
}