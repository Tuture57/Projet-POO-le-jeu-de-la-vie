#include "file.h"
#include "classic_grid.h"
#include "classic_cell.h" // Add this line
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <memory>

using namespace std;
namespace fs = std::filesystem;

File::File() : filename("") {}

File::File(string fname) : filename(fname) {}

std::unique_ptr<ClassicGrid> File::loadGrid() {
    vector<vector<std::unique_ptr<Cell>>> cells;
    vector<std::unique_ptr<Cell>> line;
    string l;
    char ch;
    int width = 0, height = 0;
    ifstream gridFile (filename);
    if (gridFile.is_open()) {
        getline(gridFile,l);
        int pos = l.find(' ');
        height = stoi(l.substr(0,pos));
        width = stoi(l.substr(pos + 1));
        
        for (int i = 0; i < height; i++) {
            getline(gridFile,l);
            int cellCol = 0;

            for (int j = 0; j < l.length() && cellCol < width; j++) {
                ch = l[j];
                if (ch !=' ' && ch !='\n') {
                    line.push_back(std::make_unique<ClassicCell>(cellCol, i, ch - '0'));
                    cellCol++;
                }
            }
            cells.push_back(std::move(line));
            line.clear();
        }
        gridFile.close();
    }
    return std::make_unique<ClassicGrid>(width, height, std::move(cells));
}

void File::saveGrid(const ClassicGrid& grid, int iteration) {
    string baseFileName = filename.substr(0, filename.find_last_of("."));
    string extension = filename.substr(filename.find_last_of("."));

    fs::create_directory(baseFileName+"_out");
    string filename = baseFileName+"_out/"+baseFileName+"_out_"+to_string(iteration)+extension;

    ofstream gridFile(filename);
    vector<vector<Cell*>> cells;
    for (const auto& row : grid.getCells()) {
        vector<Cell*> cellRow;
        for (const auto& cell : row) {
            cellRow.push_back(cell.get());
        }
        cells.push_back(std::move(cellRow));
    }
    if (gridFile.is_open()) {
        gridFile << grid.getHeight() << " " << grid.getWidth() << endl;
        for (int i = 0; i < grid.getHeight(); i++) {
            for (int j = 0; j < grid.getWidth(); j++) {
                gridFile << cells[i][j]->getAlive();
                if (j < grid.getWidth() - 1) {
                    gridFile << " ";
                }
            }
            gridFile << endl;
        }
        gridFile.close();
    }
}