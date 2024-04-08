#include "player.h"
#include "enemy.h"
#include "raylib.h"
#include <iostream>
#include "drawingplatform.h"
#include "platform.h"

int main()
{
    
    player playerInstance;
    drawingplatform GameStuff;
    enemy Enemy;

    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    GameStuff.InitializePlatforms();  
    
    Texture2D BocksImage = LoadTexture("assets/Bockey.png");
    Vector2 Bocks = { (float)(GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };



    Texture2D BocksEnemyImage = LoadTexture("assets/Bockey_Enemy.png");
    Vector2 BocksEnemy = { (float)(GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };

    float deltaTime = GetFrameTime();  
    GameStuff.timer = 0;
    Bocks.x = 500;
    Bocks.y = 500;
    
    // ToggleFullscreen();

    BocksEnemy.x = (float)GameStuff.SCREEN_WIDTH/2;
    BocksEnemy.y = (float)GameStuff.SCREEN_HEIGHT/2;
    
while (!WindowShouldClose())
{
    
        // std::cout <<BocksEnemy.x <<std::endl;
    std::cout << GameStuff.collided <<std::endl;
    
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