#include <raylib.h>
#include "game.h"

double lastUpdatedTime = 0.0;

bool eventTriggered(double interval) {
    double currentTime = GetTime();

    if (currentTime - lastUpdatedTime >= interval) {
        lastUpdatedTime = currentTime;
        return true;
    }

    return false;
}

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

        if (eventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    // close window
    CloseWindow();

    return 0;
}
