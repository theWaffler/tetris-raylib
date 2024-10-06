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
        void Draw();
        ~Block(); //destructor
    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
};
