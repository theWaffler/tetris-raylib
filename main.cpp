#include <raylib.h>
#include "grid.h"

int main() {
    Color darkBlue = {44, 44, 127, 255};  // built in struct
    const int winHeight = 600;
    const int winWidth = 300;
    // initialize window
    InitWindow(winWidth, winHeight, "TETRIS");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.grid[3][5] = 7;
    grid.grid[5][5] = 23;
    grid.Print();

    while (WindowShouldClose() == false) {
    BeginDrawing();
    ClearBackground(darkBlue);
    grid.Draw();

    EndDrawing();
    }

    // close window
    CloseWindow();

    return 0;
}
