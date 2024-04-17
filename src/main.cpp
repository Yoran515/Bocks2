#include "player.h"
#include "enemy.h"
#include "raylib.h"
#include <iostream>
#include "game.h"
#include "platform.h"
#include "entity.h"

int main()
{
    player playerInstance;
    game GameStuff;
    enemy Enemy;
    entity Entitystuff;

    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    GameStuff.InitializePlatforms();  

 

    Texture2D BocksImage = LoadTexture("assets/Bockey.png");
    Vector2 Bocks = { 500, 500 }; 

    Texture2D BocksEnemyImage = LoadTexture("assets/Bockey_Enemy.png");
    Vector2 BocksEnemy = { 900, 500 }; 

    Texture2D BocksEnemyPetImage = LoadTexture("assets/Bockey_Enemy_Pet.png");
    float rotationAngle = 1.0f;
    float rotationSpeed = 90.0f; 
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        float deltaTime = GetFrameTime();

        playerInstance.PlayerMovement(Bocks, BocksImage); 
        Enemy.EnemyMovement(BocksEnemy, BocksEnemyImage, deltaTime); 

        
        
        for (const auto& platform : GameStuff.platforms)
        {
            platform.Draw();
        }
        std::cout <<rotationAngle << std::endl;
    
        rotationAngle += rotationSpeed * deltaTime;
        
        if (rotationAngle >= 360.0f) 
        {
             rotationAngle -= 360.0f; 
        }

        Vector2 offset = { 250, 250 }; 
    
        
        Vector2 bocksEnemyPet = 
        {
            BocksEnemy.x + offset.x * cos(DEG2RAD * rotationAngle) - offset.y * sin(DEG2RAD * rotationAngle),
            BocksEnemy.y + offset.x * sin(DEG2RAD * rotationAngle) + offset.y * cosf(DEG2RAD * rotationAngle)
            
        };

    
        DrawTexture(BocksImage, (int)Bocks.x, (int)Bocks.y, WHITE);
        DrawTexture(BocksEnemyImage, (int)BocksEnemy.x, (int)BocksEnemy.y, WHITE);
        DrawTexture(BocksEnemyPetImage, (int)bocksEnemyPet.x, (int)bocksEnemyPet.y, WHITE);

        EndDrawing();
    }

    UnloadTexture(BocksEnemyPetImage);
    UnloadTexture(BocksEnemyImage);
    UnloadTexture(BocksImage);
    CloseWindow();

    return 0;
}