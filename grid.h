#pragma once
#include <raylib.h>
#include <vector>

class Grid {
    public:
        Grid();
        void initialize();
        void Print();
        void Draw();
        bool IsCellOutside(int row, int column);
        bool IsCellEmpty(int row, int column);
        int grid[20][10];
        int ClearFullRows();

    ~Grid();  // destructor
    private:
        int numRows;
        int numCols;
        int celSize;
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        std::vector<Color> colors;

};
