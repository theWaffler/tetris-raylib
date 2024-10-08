#include <raylib.h>
#include "game.h"
#include "color.h"
#include <iostream>

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
    const int winHeight = 600;
    const int winWidth = 300;
    // initialize window
    InitWindow(500, 620, "TETRIS!");
    SetTargetFPS(60);

    Font font = LoadFontEx("jet.ttf", 64, 0, 0);

    // game loop
    while (WindowShouldClose() == false) {
        UpdateMusicStream(game.music);
        game.HandleInput();

        if (eventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "SCORE", {360,15}, 38, 2, WHITE);
        DrawTextEx(font, "NEXT", {372,175}, 38, 2, WHITE);

        if (game.gameOver) {
            DrawTextEx(font, "GAME OVER", {320,450}, 38, 2, WHITE);
        }

        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 +(170 - textSize.x)/2,65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    // close window
    CloseWindow();

    return 0;
}
