#include <raylib.h>
#include "game.h"

int main() {
    Game game = Game();
    Color darkBlue = {44, 44, 127, 255};  // built in struct
    const int winHeight = 600;
    const int winWidth = 300;
    // initialize window
    InitWindow(winWidth, winHeight, "TETRIS!");
    SetTargetFPS(60);

    // game loop
    while (WindowShouldClose() == false) {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    // close window
    CloseWindow();

    return 0;
}
