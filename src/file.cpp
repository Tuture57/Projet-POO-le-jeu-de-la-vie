#include "file.h"
#include <iostream>
#include <fstream>
#include <vector>


File::File(string fname) : filename(fname) {}

Grid File::loadGrid() {
    vector<vector<Cell>> cells;
    vector<Cell> line;
    string l1;
    char ch;
    ifstream gridFile (argv[1]);
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
                    line.push_back();
                }
            }
            cells.push_back(line);
            line.clear();
        }
        gridFile.close();
    }
}

void File::saveGrid(Grid grid) {

}