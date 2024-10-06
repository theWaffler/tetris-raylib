#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main() {
    Color darkBlue = {44, 44, 127, 255};  // built in struct
    const int winHeight = 600;
    const int winWidth = 300;
    // initialize window
    InitWindow(winWidth, winHeight, "TETRIS");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    TBlock block = TBlock();

    while (WindowShouldClose() == false) {
    BeginDrawing();
    ClearBackground(darkBlue);
    grid.Draw();
    block.Draw();
    EndDrawing();
    }

    // close window
    CloseWindow();

    return 0;
}
