#ifndef FILE_SAVER_H
#define FILE_SAVER_H

#include "classic_grid.h"

class FileSaver {
    public:
        virtual ~FileSaver() = default;
        virtual void saveGrid(const Grid& grid, int iteration) = 0;
};

#endif