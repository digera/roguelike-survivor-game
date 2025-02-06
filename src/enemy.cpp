#include "enemy.h"
#include "raylib.h"
#include <stdlib.h>
#include <math.h>

void InitEnemy(Enemy* enemy, Vector2 position, float speed, int health, EnemyType type) {
    enemy->position = position;
    enemy->speed = speed;
    enemy->health = health;
    enemy->type = type;
}

void UpdateEnemy(Enemy* enemy, Vector2 playerPosition) {
    Vector2 direction = { playerPosition.x - enemy->position.x, playerPosition.y - enemy->position.y };
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction.x /= length;
    direction.y /= length;

    enemy->position.x += direction.x * enemy->speed * GetFrameTime();
    enemy->position.y += direction.y * enemy->speed * GetFrameTime();
}

void DrawEnemy(Enemy* enemy) {
    Color color;
    switch (enemy->type) {
        case BASIC:
            color = RED;
            break;
        case FAST:
            color = GREEN;
            break;
        case STRONG:
            color = PURPLE;
            break;
    }
    DrawCircleV(enemy->position, 20, color);
}

void SpawnEnemies(Enemy* enemies, int* enemyCount, int maxEnemies, Vector2 playerPosition) {
    if (*enemyCount < maxEnemies) {
        Vector2 spawnPosition = { (float)(rand() % 800), (float)(rand() % 600) };
        float speed = 100.0f + (rand() % 100);
        int health = 50 + (rand() % 50);
        EnemyType type = (EnemyType)(rand() % 3);

        InitEnemy(&enemies[*enemyCount], spawnPosition, speed, health, type);
        (*enemyCount)++;
    }

    for (int i = 0; i < *enemyCount; i++) {
        UpdateEnemy(&enemies[i], playerPosition);
    }
}
