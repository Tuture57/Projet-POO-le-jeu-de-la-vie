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
    string l;
    char ch;
    int width, height;
    ifstream gridFile (filename);
    if (gridFile.is_open()) {
        getline(gridFile,l);
        int pos = l.find(' ');
        height = stoi(l.substr(0,pos));
        width = (stoi(l.substr(pos + 1))*2);
        for (int i = 0; i < height; i++) {
            getline(gridFile,l);
            for (int j = 0; j < width; j++) {
                ch = l[j];
                if (ch !=' ' && ch !='\n') {
                    line.push_back(Cell(j, i, ch - '0'));
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
    vector<vector<Cell>> cells = grid.getCells();
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