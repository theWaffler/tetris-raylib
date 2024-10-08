#include <raylib.h>
#include <emscripten/emscripten.h>  // Include Emscripten for the web build
#include "game.h"
#include "color.h"
#include <iostream>

double lastUpdatedTime = 0.0;
Game game;  // Declare the game globally to access in the loop function

bool eventTriggered(double interval) {
    double currentTime = GetTime();

    if (currentTime - lastUpdatedTime >= interval) {
        lastUpdatedTime = currentTime;
        return true;
    }

    return false;
}

// Define a function for the game loop that will be called every frame
void GameLoop() {
    UpdateMusicStream(game.music);  // Ensure music stream is updated
    game.HandleInput();

    // Move block down every 0.2 seconds
    if (eventTriggered(0.2)) {
        game.MoveBlockDown();
    }

    // Start drawing
    BeginDrawing();
    ClearBackground(darkBlue);  // Clear the screen

    // Draw UI elements and game state
    Font font = LoadFontEx("jet.ttf", 64, 0, 0);  // Ensure font is loaded
    DrawTextEx(font, "SCORE", {360, 15}, 38, 2, WHITE);
    DrawTextEx(font, "NEXT", {372, 175}, 38, 2, WHITE);

    if (game.gameOver) {
        DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
    }

    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
    DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

    game.Draw();  // Draw the game state (blocks, grid, etc.)

    EndDrawing();  // End rendering
}

int main() {
    // Initialize window and audio
    InitWindow(500, 620, "TETRIS!");
    InitAudioDevice();
    SetTargetFPS(60);  // Set the target FPS

    // Load assets like fonts and music
    Font font = LoadFontEx("jet.ttf", 64, 0, 0);
    game.music = LoadMusicStream("daft.wav");
    PlayMusicStream(game.music);

    // Instead of a while loop, we set the game loop with Emscripten
    emscripten_set_main_loop(GameLoop, 0, 1);

    // Resources will be unloaded automatically when the browser closes the page
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
