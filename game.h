#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();

    private:
        Grid grid;
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;

        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        bool IsCellOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();


};
