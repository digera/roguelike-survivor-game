#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

typedef enum EnemyType {
    BASIC,
    FAST,
    STRONG
} EnemyType;

typedef struct Enemy {
    Vector2 position;
    float speed;
    int health;
    EnemyType type;
} Enemy;

void InitEnemy(Enemy* enemy, Vector2 position, float speed, int health, EnemyType type);
void UpdateEnemy(Enemy* enemy, Vector2 playerPosition);
void DrawEnemy(Enemy* enemy);
void SpawnEnemies(Enemy* enemies, int* enemyCount, int maxEnemies, Vector2 playerPosition);

#endif // ENEMY_H
