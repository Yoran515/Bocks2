#include "player.h"
#include "enemy.h"
#include "raylib.h"
#include <iostream>
#include "game.h"
#include "platform.h"

int main()
{
    
    player playerInstance;
    game GameStuff;
    enemy Enemy;

    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    GameStuff.InitializePlatforms();  // Initialize platforms
    
    Texture2D BocksImage = LoadTexture("assets/Mokey.png");
    Vector2 Bocks = { static_cast<float>(GameStuff.SCREEN_WIDTH) / 2.0f, static_cast<float>(GameStuff.SCREEN_HEIGHT) - BocksImage.height };


    Texture2D BocksEnemyImage = LoadTexture("assets/Mokey.png");
    Vector2 BocksEnemy = { static_cast<float>(GameStuff.SCREEN_WIDTH) / 2.0f, static_cast<float>(GameStuff.SCREEN_HEIGHT) - BocksImage.height };

    float deltaTime = GetFrameTime();  // Get the time between frames
    GameStuff.timer = 0;
    Bocks.x = 500;
    Bocks.y = 500;

    BocksEnemy.x = 960;
    BocksEnemy.y = 540;
    
    while (!WindowShouldClose())
    {
         std::cout <<BocksEnemy.x <<std::endl;
        // GameStuff.CheckCollision(playerInstance, MokeyImage, Mokey);
        for (const auto& platform : GameStuff.platforms)
        {
            platform.Draw();
        }
 
        playerInstance.PlayerMovement(Bocks, BocksImage, deltaTime); 
        Enemy.EnemyMovement(BocksEnemy, BocksEnemyImage, deltaTime); 
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(BocksImage, Bocks.x, Bocks.y, WHITE);
        DrawTexture(BocksEnemyImage, BocksEnemy.x, BocksEnemy.y, WHITE);
    
    EndDrawing();
    }

    UnloadTexture(BocksImage);
    UnloadTexture(BocksEnemyImage);
    CloseWindow();

    return 0;
}