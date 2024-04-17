
#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h" 


class enemy
{
private:
    /* data */
public:
  
bool Left = false;
bool Right = true;

float SpeedEnemy = 8.0f;
void EnemyMovement(Vector2 &BocksEnemy, Texture2D BocksEnemyImage, float deltaTime);

};
#endif