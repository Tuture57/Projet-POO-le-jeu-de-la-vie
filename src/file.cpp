#include "file.h"
#include "grid.h"
#include <iostream>
#include <fstream>
#include <vector>

//Choses a modifier :
// - le nom du filename voir si string ca passe ou si il faut convertir en char
// - Voir pour la structure des vecteurs avec les objets Cells a implémenter il faudrait revoir les méthodes

File::File(string fname) : filename(fname) {}

Grid File::loadGrid() {
    vector<vector<Cell>> cells;
    vector<Cell> line;
    string l1;
    char ch;
    ifstream gridFile (filename);
    if (gridFile.is_open()) {
        getline(gridFile,l1);
        int pos = l1.find(' ');
        int height = stoi(l1.substr(0,pos));
        int width = (stoi(l1.substr(pos + 1))*2);
        for (int i = 0; i < height; i++) {
            getline(gridFile,l1);
            for (int j = 0; j < width; j++) {
                ch = l1[j];
                if (ch !=' ' && ch !='\n') {
                    line.push_back(Cell(width, height, ch));
                }
            }
            cells.push_back(line);
            line.clear();
        }
        gridFile.close();
    }
    return Grid(width, height, cells);
}

void File::saveGrid(Grid grid) {
    ofstream gridFile (filename);
    vector<vector<Cell>> cells = grid.cells();
    if (gridFile.is_open()) {
        gridFile << grid.getHeight() << " " << grid.getWidth() << endl;
        for (int i = 0; i < grid.getHeight(); i++) {
            for (int j = 0; j < grid.getWidth(); j++) {
                gridFile << cells[i][j].isAlive();
                if (j < grid.getWidth() - 1) {
                    gridFile << " ";
                }
            }
            gridFile << endl;
        }
        gridFile.close();
    }
}