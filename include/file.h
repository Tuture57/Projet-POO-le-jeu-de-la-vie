#ifndef FILE_H
#define FILE_H

#include "classic_grid.h"
#include "file_loader.h"
#include "file_saver.h"
#include <string>
#include <memory>

class File : public FileLoader, public FileSaver {
    private:
        std::string filename;
    public:
        File();
        File(std::string fname);
        ~File() = default;
        std::unique_ptr<ClassicGrid> loadGrid() override;
        void saveGrid(const ClassicGrid& grid, int iteration) override;
};

#endif