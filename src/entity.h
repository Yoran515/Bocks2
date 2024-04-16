
#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h" 


class entity
{
private:
    /* data */
public:
    game GameStuff;

    Texture2D BocksImage = LoadTexture("assets/Bockey.png");
    Vector2 Bocks = { (GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };


    Texture2D BocksEnemyImage = LoadTexture("assets/Bockey_Enemy.png");
    Vector2 BocksEnemy = { (GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };
void Entity();

};
#endif