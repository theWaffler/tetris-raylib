#include "block.h"
#include "position.h"

class LBlock : public Block {
    public:
        LBlock() {
            id = 1;
            // rotation state 0
            cells[0] = {Position(0,2),Position(1,0), Position(1,1), Position(1,2)};
            // rotation state 1
            cells[1] = {Position(0,1),Position(1,1), Position(2,1), Position(2,2)};
            // rotation state 2
            cells[2] = {Position(1,0),Position(1,1), Position(1,2), Position(2,0)};
            // rotation state 3
            cells[3] = {Position(0,0),Position(0,1), Position(1,1), Position(2,1)};
            Move(0,3); // spaws in the middle of the board
        }
};

class JBlock : public Block {
    public:
        JBlock() {
            id = 2;
            // rotation state 0
            cells[0] = {Position(0,0),Position(1,0), Position(1,1), Position(1,2)};
            // rotation state 1
            cells[1] = {Position(0,1),Position(0,2), Position(1,1), Position(2,1)};
            // rotation state 2
            cells[2] = {Position(1,0),Position(1,1), Position(1,2), Position(2,2)};
            // rotation state 3
            cells[3] = {Position(0,1),Position(1,1), Position(2,0), Position(2,1)};
            Move(0,3); // spaws in the middle of the board
        }
};

class IBlock : public Block {
    public:
        IBlock() {
            id = 3;
            // rotation state 0
            cells[0] = {Position(1,0),Position(1,1), Position(1,2), Position(1,3)};
            // rotation state 1
            cells[1] = {Position(0,2),Position(1,2), Position(2,2), Position(3,2)};
            // rotation state 2
            cells[2] = {Position(2,0),Position(2,1), Position(2,2), Position(2,3)};
            // rotation state 3
            cells[3] = {Position(0,1),Position(1,1), Position(2,1), Position(3,1)};
            Move(-1,3); // spaws in the middle of the board
        }
};

class OBlock : public Block {
    public:
        OBlock() {
            id = 4;
            // rotation state 0
            cells[0] = {Position(0,0),Position(0,1), Position(1,0), Position(1,1)};
            Move(0,4); // spaws in the middle of the board
        }
};

class SBlock : public Block {
    public:
        SBlock() {
            id = 5;
            // rotation state 0
            cells[0] = {Position(0,1),Position(0,2), Position(1,0), Position(1,1)};
            // rotation state 1
            cells[1] = {Position(0,1),Position(1,1), Position(1,2), Position(2,2)};
            // rotation state 2
            cells[2] = {Position(1,1),Position(1,2), Position(2,0), Position(2,1)};
            // rotation state 3
            cells[3] = {Position(0,0),Position(1,0), Position(1,1), Position(2,1)};
            Move(0,3); // spaws in the middle of the board
        }
};

class TBlock : public Block {
    public:
        TBlock() {
            id = 6;
            // rotation state 0
            cells[0] = {Position(0,1),Position(1,0), Position(1,1), Position(1,2)};
            // rotation state 1
            cells[1] = {Position(0,1),Position(1,1), Position(1,2), Position(2,1)};
            // rotation state 2
            cells[2] = {Position(1,0),Position(1,1), Position(1,2), Position(2,1)};
            // rotation state 3
            cells[3] = {Position(0,1),Position(1,0), Position(1,1), Position(2,1)};
            Move(0,3); // spaws in the middle of the board
        }
};

class ZBlock : public Block {
    public:
        ZBlock() {
            id = 7;
            // rotation state 0
            cells[0] = {Position(0,0),Position(0,1), Position(1,1), Position(1,2)};
            // rotation state 1
            cells[1] = {Position(0,2),Position(1,1), Position(1,2), Position(2,1)};
            // rotation state 2
            cells[2] = {Position(1,0),Position(1,1), Position(2,1), Position(2,2)};
            // rotation state 3
            cells[3] = {Position(0,1),Position(1,0), Position(1,1), Position(2,0)};
            Move(0,3); // spaws in the middle of the board
        }
};
