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

    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    GameStuff.InitializePlatforms();  
    
    Texture2D BocksImage = LoadTexture("assets/Mokey.png");
    Vector2 Bocks = { (float)(GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };


    Texture2D BocksEnemyImage = LoadTexture("assets/Mokey.png");
    Vector2 BocksEnemy = { (float)(GameStuff.SCREEN_WIDTH) / 2.0f,(float) (GameStuff.SCREEN_HEIGHT) - BocksImage.height };

    float deltaTime = GetFrameTime();  // Get the time between frames
    GameStuff.timer = 0;

    Bocks.x = 500;
    Bocks.y = 500;

    BocksEnemy.x = 960;
    BocksEnemy.y = 540;
    
    while (!WindowShouldClose())
    {

        BeginDrawing();
        std::cout << "TEST" <<std::endl;
        for (const auto& platform : GameStuff.platforms)
        {
            platform.Draw();
        }
        ClearBackground(RAYWHITE);

        DrawTexture(BocksImage, (int)Bocks.x, (int)Bocks.y, WHITE);
        DrawTexture(BocksEnemyImage, (int)BocksEnemy.x, (int)BocksEnemy.y, WHITE);
       
        
    
    EndDrawing();
    }

    UnloadTexture(BocksEnemyImage);
    UnloadTexture(BocksImage);
    CloseWindow();

    return 0;
}