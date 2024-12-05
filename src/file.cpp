#include "file.h"
#include "grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

File::File() : filename("") {}

File::File(string fname) : filename(fname) {}

Grid File::loadGrid() {
    vector<vector<Cell>> cells;
    vector<Cell> line;
    string l;
    char ch;
    int width, height;
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
                    line.push_back(Cell(cellCol, i, ch - '0'));
                    cellCol++;
                }
            }
            cells.push_back(line);
            line.clear();
        }
        gridFile.close();
    }
    return Grid(width, height, cells);
}

void File::saveGrid(Grid grid, int iteration) {
    string baseFileName = filename.substr(0, filename.find_last_of("."));
    string extension = filename.substr(filename.find_last_of("."));

    fs::create_directory(baseFileName+"_out");
    string filename = baseFileName+"_out/"+baseFileName+"_out_"+to_string(iteration)+extension;

    ofstream gridFile(filename);
    vector<vector<Cell>> cells = grid.getCells();
    if (gridFile.is_open()) {
        gridFile << grid.getHeight() << " " << grid.getWidth() << endl;
        for (int i = 0; i < grid.getHeight(); i++) {
            for (int j = 0; j < grid.getWidth(); j++) {
                gridFile << cells[i][j].getAlive();
                if (j < grid.getWidth() - 1) {
                    gridFile << " ";
                }
            }
            gridFile << endl;
        }
        gridFile.close();
    }
}