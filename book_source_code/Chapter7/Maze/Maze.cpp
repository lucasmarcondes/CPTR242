#include "Maze.h"

#include <fstream>
#include <iostream>
#include <string>

Maze::Maze(std::ifstream& inFile) {
    using namespace std;
    int rowIndex, colIndex;
    inFile >> maxRows >> maxCols;
    string row;
    for (rowIndex = 1; rowIndex <= maxRows; rowIndex++) {
        inFile >> row;
        for (colIndex = 1; colIndex <= maxCols; colIndex++)
            maze[rowIndex][colIndex] = row[colIndex - 1];
        maze[rowIndex][0] = '+';
        maze[rowIndex][maxCols + 1] = '+';
    }
    for (colIndex = 0; colIndex <= maxCols + 1; colIndex++) {
        maze[0][colIndex] = '+';
        maze[maxRows + 1][colIndex] = '+';
    }
}

Maze::Maze(const Maze& anotherMaze) {
    maxRows = anotherMaze.maxRows;
    maxCols = anotherMaze.maxCols;
    for (int rowIndex = 0; rowIndex <= maxRows + 1; rowIndex++)
        for (int colIndex = 0; colIndex <= maxCols + 1; colIndex++)
            maze[rowIndex][colIndex] = anotherMaze.maze[rowIndex][colIndex];
}

void Maze::Print() {
    using namespace std;
    int rowIndex, colIndex;

    cout << "Maze" << endl;
    for (rowIndex = 1; rowIndex <= maxRows; rowIndex++) {
        for (colIndex = 1; colIndex <= maxCols; colIndex++)
            cout << " " << maze[rowIndex][colIndex];
        cout << endl;
    }
}

void Try(char[][10], int row, int col, bool& free);

bool Maze::TryToEscape(int startRow, int startCol) {
    bool free = false;
    Try(maze, startRow, startCol, free);
    return free;
}

void Try(char maze[][10], int row, int col, bool& free) {
    if (!free && (maze[row][col]) != '*' && (maze[row][col]) != '+')
        if (maze[row][col] == 'E')
            free = true;
        else {
            maze[row][col] = '*';
            Try(maze, row + 1, col, free);
            if (!free)
                Try(maze, row - 1, col, free);
            if (!free)
                Try(maze, row, col + 1, free);
            if (!free)
                Try(maze, row, col - 1, free);
        }
}
