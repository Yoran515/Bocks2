#include "player.h"
#include "enemy.h"
#include "raylib.h"
#include <iostream>
#include "game.h"
#include "platform.h"
#include "entity.h"

int main()
{
    //Sub Class maken genaamd entity en doe daarin DrawTexture daarin de Enemy en de Player!!

    player playerInstance;
    game GameStuff;
    enemy Enemy;
    entity Entitystuff;

    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    GameStuff.InitializePlatforms();  
    

    // float deltaTime = GetFrameTime();  // Get the time between frames
    GameStuff.timer = 0;

    Texture2D BocksImage = LoadTexture("assets/Bockey.png");
    Vector2 Bocks = { (GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };

    Texture2D BocksEnemyImage = LoadTexture("assets/Bockey_Enemy.png");
    Vector2 BocksEnemy = { (GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };
    Bocks.x = 500;
    Bocks.y = 500;

    BocksEnemy.x = 900;
    BocksEnemy.y = 500;
    
    while (!WindowShouldClose())

    {
    
        BeginDrawing();
        ClearBackground(RAYWHITE);
         
        playerInstance.PlayerMovement(Bocks, BocksImage); 
        // Enemy.EnemyMovement(Entitystuff.BocksEnemy, Entitystuff.BocksEnemyImage, deltaTime); 

        for (const auto& platform : GameStuff.platforms)
        {
            platform.Draw();
        }
    
        DrawTexture(BocksImage, (int)Bocks.x, (int)Bocks.y, WHITE);
        DrawTexture(BocksEnemyImage, (int)BocksEnemy.x, (int)BocksEnemy.y, WHITE);

       

        EndDrawing();
    }

    UnloadTexture(BocksEnemyImage);
    UnloadTexture(BocksImage);
    CloseWindow();

    return 0;
}