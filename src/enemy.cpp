#include "raylib.h"
#include <iostream>
#include "enemy.h"
#include "game.h"

void enemy::EnemyMovement(Vector2 &BocksEnemy, Texture2D BocksEnemyImage, float deltaTime)
{

    game GameStuff;
     
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
