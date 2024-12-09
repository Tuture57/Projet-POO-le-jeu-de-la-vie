#include "file.h"
#include "classic_grid.h"
#include "classic_cell.h"
#include "obstacle_cell.h"
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

std::unique_ptr<Grid> File::loadGrid() {
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
                    if (ch == '0' || ch == '1') {
                        line.push_back(std::make_unique<ClassicCell>(cellCol, i, ch - '0'));
                    } else if (ch == '2' || ch == '3') {
                        bool alive = (ch == '2');
                        line.push_back(std::make_unique<ObstacleCell>(cellCol, i, alive));
                    }
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

void File::saveGrid(const Grid& grid, int iteration) {
    string baseFileName = filename.substr(0, filename.find_last_of("."));
    string extension = filename.substr(filename.find_last_of("."));

    fs::create_directory(baseFileName+"_out");
    string filename = baseFileName+"_out/"+baseFileName+"_out_"+to_string(iteration)+extension;

    ofstream gridFile(filename);
    const auto& cells = grid.getCells();

    if (gridFile.is_open()) {
        gridFile << grid.getHeight() << " " << grid.getWidth() << endl;
        for (int i = 0; i < grid.getHeight(); i++) {
            for (int j = 0; j < grid.getWidth(); j++) {
                if (auto* obstacle = dynamic_cast<ObstacleCell*>(cells[i][j].get())) {
                    gridFile << (obstacle->getAlive() ? "2" : "3");
                } else {
                    gridFile << (cells[i][j]->getAlive() ? "1" : "0");
                }
                if (j < grid.getWidth() - 1) {
                    gridFile << " ";
                }
            }
            gridFile << endl;
        }
        gridFile.close();
    }
}