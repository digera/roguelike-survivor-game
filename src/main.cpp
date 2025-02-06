#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "progression.h"
#include "scoring.h"
#include "leaderboard.h"

enum GameState {
    MAIN_MENU,
    GAMEPLAY,
    GAME_OVER
};

int main() {
    // Initialize the game window and set up the game world
    InitWindow(800, 600, "Endless Roguelike Survivor Game");
    SetTargetFPS(60);

    GameState gameState = MAIN_MENU;

    Player player;
    InitPlayer(&player);

    while (!WindowShouldClose()) {
        // Main game loop to handle game updates, rendering, and input processing
        switch (gameState) {
            case MAIN_MENU:
                // Handle main menu logic
                if (IsKeyPressed(KEY_ENTER)) {
                    gameState = GAMEPLAY;
                }
                break;
            case GAMEPLAY:
                // Update game world
                UpdatePlayer(&player);

                // Render game world
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawPlayer(&player);
                EndDrawing();

                // Check for game over condition
                if (player.health <= 0) {
                    gameState = GAME_OVER;
                }
                break;
            case GAME_OVER:
                // Handle game over logic
                if (IsKeyPressed(KEY_ENTER)) {
                    gameState = MAIN_MENU;
                }
                break;
        }
    }

    CloseWindow();
    return 0;
}
