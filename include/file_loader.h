#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "classic_grid.h"

class FileLoader {
    public:
        virtual ~FileLoader() = default;
        virtual ClassicGrid loadGrid() = 0;
};

#endif