#include "raylib.h"
#include <iostream>
#include "enemy.h"
#include "drawingplatform.h"


void enemy::EnemyMovement(Vector2 &BocksEnemy, Texture2D BocksEnemyImage, float deltaTime)
{

    drawingplatform GameStuff;
    std::cout <<"test" <<std::endl;
    // BocksEnemyImage = LoadTexture("assets/Bockey_Enemy.png");
    // BocksEnemy = { (float)(GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksEnemyImage.height };

    BocksEnemy.x = (float)GameStuff.SCREEN_WIDTH/2;
    BocksEnemy.y = (float)GameStuff.SCREEN_HEIGHT/2;

  
    if(Left == true)  
    {
        if(Right == false)  
        {
            BocksEnemy.x -= SpeedEnemy;
        }
    }
    if(Right == true)  
    {
        if(Left == false)  
        {
            BocksEnemy.x += SpeedEnemy;
        }
    }
    
    if(BocksEnemy.x < 500)
    {
        Right = true;
        Left = false;
    }

      if(BocksEnemy.x > 1500)
    {
        Right = false;
        Left = true;
    }


}