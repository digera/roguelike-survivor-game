#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
    Vector2 position;
    float speed;
    int health;
} Player;

void InitPlayer(Player* player);
void UpdatePlayer(Player* player);
void DrawPlayer(Player* player);

#endif // PLAYER_H
