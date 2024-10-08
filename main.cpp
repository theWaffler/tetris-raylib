#include <raylib.h>
#include "game.h"
#include "color.h"
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE void expose_audio_context() {
        EM_ASM(
            Module.audioCtx = SDL_audioContext;
        );
    }
}
#endif

double lastUpdatedTime = 0.0;

bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdatedTime >= interval) {
        lastUpdatedTime = currentTime;
        return true;
    }
    return false;
}

void GameLoop(void* arg) {
    Game* game = static_cast<Game*>(arg);

    UpdateMusicStream(game->music);
    game->HandleInput();
    if (eventTriggered(0.2)) {
        game->MoveBlockDown();
    }

    BeginDrawing();
    ClearBackground(darkBlue);

    Font font = GetFontDefault();  // Use default font instead of loading a custom one

    DrawText("SCORE", 360, 15, 38, WHITE);
    DrawText("NEXT", 372, 175, 38, WHITE);
    if (game->gameOver) {
        DrawText("GAME OVER", 320, 450, 38, WHITE);
    }

    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
    char scoreText[10];
    sprintf(scoreText, "%d", game->score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    DrawText(scoreText, 320 + (170 - textSize.x)/2, 65, 38, WHITE);
    DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

    game->Draw();
    EndDrawing();
}

int main() {
    const int winHeight = 600;
    const int winWidth = 300;

    InitWindow(500, 620, "TETRIS!");
    SetTargetFPS(60);

    InitAudioDevice();

    #ifdef __EMSCRIPTEN__
    expose_audio_context();
    #endif

    Game game = Game();
    if (!game.AudioLoadedSuccessfully()) {
        TraceLog(LOG_ERROR, "Failed to load one or more audio files");
    }

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(GameLoop, &game, 0, 1);
    #else
    while (!WindowShouldClose()) {
        GameLoop(&game);
    }
    #endif

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
