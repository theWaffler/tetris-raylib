#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        bool gameOver;
        int score;
        Music music;
        bool AudioLoadedSuccessfully() const;


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
        void Reset();
        void MoveBlockLeft();
        void MoveBlockRight();
        void UpdateScore(int LinesCleared, int moveDownPoints);
        bool BlockFits();
        Sound rotateSound;
        Sound clearSound;
};
