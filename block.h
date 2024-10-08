#pragma once
#include <raylib.h>
#include <vector>
#include <map>
#include "position.h"

class Block {
    public:
        Block();
        int id;
        std::map<int, std::vector<Position>> cells;
        void Draw(int offsetX, int offsetY);
        void Move(int row, int column);
        void Rotate();
        void UndoRotate();
        std::vector<Position> GetCellPosition();
        ~Block(); //destructor

    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
        int rowOffset;
        int columnOffset;
};
