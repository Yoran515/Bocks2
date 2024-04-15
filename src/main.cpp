#include "player.h"
#include "enemy.h"
#include "raylib.h"
#include <iostream>
#include "drawingplatform.h"
#include "platform.h"
#include "entity.h"

int main()
{
    //Sub Class maken genaamd entity en doe daarin DrawTexture daarin de Enemy en de Player!!

    player playerInstance;
    drawingplatform GameStuff;
    enemy Enemy;

    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    GameStuff.InitializePlatforms();  
    
    float deltaTime = GetFrameTime();  
    GameStuff.timer = 0;

    Texture2D BocksImage = LoadTexture("assets/Bockey.png");
    Vector2 Bocks = { (float)(GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };

    // ToggleFullscreen();

    Texture2D BocksEnemyImage = LoadTexture("assets/Bockey_Enemy.png");
    Vector2 BocksEnemy = { (float)(GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksEnemyImage.height };

    Bocks.x = 500;
    Bocks.y = 500;
    BocksEnemy.x =800;
    BocksEnemy.y = 800;

    
    while (!WindowShouldClose())
    {
     
   
        std::cout <<Bocks.x <<std::endl;
        // std::cout << GameStuff.collided <<std::endl;
        

        // playerInstance.PlayerMovement(Bocks, BocksImage, deltaTime); 
        // Enemy.EnemyMovement(BocksEnemy, BocksEnemyImage, deltaTime); 
        BeginDrawing();

        DrawTexture(BocksImage, (int)Bocks.x, (int)Bocks.y, WHITE);
        DrawTexture(BocksEnemyImage, (int)BocksEnemy.x, (int)BocksEnemy.y, WHITE);

        ClearBackground(RAYWHITE);

        for (const auto& platform : GameStuff.platforms)
        {
            platform.Draw();
        }
      

        EndDrawing();
        
    }
   
    UnloadTexture(BocksEnemyImage);
    UnloadTexture(BocksImage);
    CloseWindow();

    return 0;
}