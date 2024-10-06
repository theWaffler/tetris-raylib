#include "block.h"
#include "color.h"
#include "position.h"
#include <raylib.h>
#include <vector>

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
}

Block::~Block() {
    // do nothing
}

void Block::Draw() {
    std::vector<Position> tiles = cells[rotationState];
    for (Position item: tiles) {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}
