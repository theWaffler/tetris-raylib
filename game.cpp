#include "game.h"
#include <random>
#include <vector>
#include "raylib.h"

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Game::~Game() {
    //nothing to do here
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput() {
    int keyPressed = GetKeyPressed();
    switch(keyPressed) {

        case KEY_A:
            MoveBlockLeft();
        break;

        case KEY_D:
            MoveBlockRight();
        break;

        case KEY_S:
            MoveBlockDown();
        break;

        case KEY_W:
            RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft() {
    currentBlock.Move(0,-1);
    if (IsCellOutside()) {
        currentBlock.Move(0,1);
    }
}

void Game::MoveBlockRight() {
    currentBlock.Move(0,1);
    if (IsCellOutside()) {
        currentBlock.Move(0,-1);
    }
}

void Game::MoveBlockDown() {
    currentBlock.Move(1,0);
    if (IsCellOutside()) {
        currentBlock.Move(-1,0);
    }
}

bool Game::IsCellOutside() {
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for (Position item:tiles) {
        if(grid.IsCellOutside(item.row, item.column)) {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock() {
    currentBlock.Rotate();
}
