#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "grid.h"

class FileLoader {
    public:
        virtual ~FileLoader() = default;
        virtual Grid loadGrid() = 0;
};

#endif