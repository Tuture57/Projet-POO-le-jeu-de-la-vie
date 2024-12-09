#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "classic_grid.h"
#include <memory>

class FileLoader {
    public:
        virtual ~FileLoader() = default;
        virtual std::unique_ptr<Grid> loadGrid() = 0;
};

#endif