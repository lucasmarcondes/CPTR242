#include <fstream>
class Maze {
  public:
    Maze(std::ifstream& inFile);
    void Print();
    bool TryToEscape(int startRow, int startCol);
    Maze(const Maze& anotherMaze);

  private:
    char maze[10][10];
    int maxRows;  // Maximum number of rows
    int maxCols;  // Maximum number of columns
};
