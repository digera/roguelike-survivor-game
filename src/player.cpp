#include "player.h"
#include "raylib.h"

void InitPlayer(Player* player) {
    player->position = { 400, 300 };
    player->speed = 200.0f;
    player->health = 100;
}

void UpdatePlayer(Player* player) {
    Vector2 direction = { 0, 0 };

    if (IsKeyDown(KEY_W)) direction.y -= 1;
    if (IsKeyDown(KEY_S)) direction.y += 1;
    if (IsKeyDown(KEY_A)) direction.x -= 1;
    if (IsKeyDown(KEY_D)) direction.x += 1;

    if (direction.x != 0 || direction.y != 0) {
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        direction.x /= length;
        direction.y /= length;
    }

    player->position.x += direction.x * player->speed * GetFrameTime();
    player->position.y += direction.y * player->speed * GetFrameTime();

    if (player->position.x < 0) player->position.x = 0;
    if (player->position.x > 800) player->position.x = 800;
    if (player->position.y < 0) player->position.y = 0;
    if (player->position.y > 600) player->position.y = 600;
}

void DrawPlayer(Player* player) {
    DrawCircleV(player->position, 20, BLUE);
}
