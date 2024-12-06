#ifndef FILE_H
#define FILE_H

#include "grid.h"
#include "file_loader.h"
#include "file_saver.h"
#include <string>

class File : public FileLoader, public FileSaver {
    private:
        std::string filename;
    public:
        File();
        File(std::string fname);
        ~File() = default;
        Grid loadGrid() override;
        void saveGrid(const Grid& grid, int iteration) override;
};

#endif