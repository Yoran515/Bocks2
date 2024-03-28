
#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h" 


class enemy
{
private:
    /* data */
public:
  
bool Left = true;
bool Right = false;

float SpeedEnemy = 0.1f;
void EnemyMovement(Vector2 &BocksEnemy, Texture2D BocksEnemyImage, float deltaTime);
};
#endif