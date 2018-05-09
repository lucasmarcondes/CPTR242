#include <fstream>
#include <iostream>
#include <string>
#include "Maze.h"
int main() {
    using namespace std;
    ifstream inFile;
    string fileName;
    int row, col;
    cout << "Enter file name" << endl;
    cin >> fileName;
    inFile.open(fileName.c_str());
    Maze maze(inFile);
    maze.Print();
    cout << "Enter row and col of starting position; " << endl << "negative row stops the processing." << endl;
    cin >> row;
    while (row >= 0) {
        Maze anotherMaze = maze;
        cin >> col;
        if (anotherMaze.TryToEscape(row, col))
            cout << "Free" << endl;
        else
            cout << "Trapped" << endl;
        cout << "Enter row and col of starting position; " << endl << "negative row stops the processing." << endl;
        cin >> row;
    }
    return 0;
}