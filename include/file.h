#ifndef FILE_H
#define FILE_H

using namespace std;

#include <string>
#include "grid.h"

class File{
    private:
        string filename;
    public:
        File();
        File(string fname);
        Grid loadGrid();
        void saveGrid(Grid grid);
};

#endif