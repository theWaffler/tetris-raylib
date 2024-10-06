#pragma once
#include <raylib.h>
#include <vector>

class Grid {
    public:
        Grid();
        void initialize();
        void Print();
        void Draw();
        int grid[20][10];

    ~Grid();  // destructor
    private:
        std::vector<Color> GetCellColors();
        int numRows;
        int numCols;
        int celSize;
        std::vector<Color> colors;
};
