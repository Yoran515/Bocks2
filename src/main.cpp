#include "player.h"
#include "enemy.h"
#include "raylib.h"
#include <iostream>
#include "game.h"
#include "platform.h"
#include "platform.h"

int main()
{
    player playerInstance;
    game GameStuff;
    enemy Enemy;
  
    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    GameStuff.InitializePlatforms();  

    Texture2D BocksImage = LoadTexture("assets/Bockey.png");
    Vector2 Bocks = { 100, 500 }; 

    Texture2D BocksEnemyImage = LoadTexture("assets/Bockey_Enemy.png");
    Vector2 BocksEnemy = { 900, 500 }; 

    Texture2D BocksEnemyPetImage = LoadTexture("assets/Bockey_Enemy_Pet.png");
    float rotationAngle = 1.0f;
    float rotationSpeed = 180.0f; 
    SetTargetFPS(60);
    Vector2 offset = { 250, 250 }; 

    
    ToggleFullscreen();
   

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        Vector2 bocksEnemyPet = 
        {
            BocksEnemy.x + offset.x * cos(DEG2RAD * rotationAngle) - offset.y * sin(DEG2RAD * rotationAngle),
            BocksEnemy.y + offset.x * sin(DEG2RAD * rotationAngle) + offset.y * cosf(DEG2RAD * rotationAngle)
            
        };
   

        Rectangle platformCollision = { };
       
        Rectangle PlayerCollision = {Bocks.x, Bocks.y,(float)BocksImage.width,(float)BocksImage.height};
        Rectangle EnemyCollision = {BocksEnemy.x, BocksEnemy.y,(float)BocksEnemyImage.width,(float)BocksEnemyImage.height};
        Rectangle EnemyPetCollision = {bocksEnemyPet.x, bocksEnemyPet.y,(float)BocksEnemyPetImage.width,(float)BocksEnemyPetImage.height};
        Rectangle Win = {1800, 500,200,500};
       
        for (const auto& platform : GameStuff.platforms)
        {
            platform.Draw();
        }
        
        float deltaTime = GetFrameTime();

        if(GameStuff.START == false )
        {
        playerInstance.PlayerMovement(Bocks, BocksImage, deltaTime, platformCollision);
        
        Enemy.EnemyMovement(BocksEnemy, BocksEnemyImage, deltaTime); 

        }
        
        
        std::cout <<GameStuff.START << std::endl;
        
    
        rotationAngle += rotationSpeed * deltaTime;

        
        if( playerInstance.won == false)
        {
            if(CheckCollisionRecs(PlayerCollision,EnemyCollision)|| CheckCollisionRecs(PlayerCollision,EnemyPetCollision))
            {
                playerInstance.died = true;
            }
        }
         if(playerInstance.died == false)
        {
            if(CheckCollisionRecs(PlayerCollision,Win))
            {
                std::cout <<"Won" << std::endl;
                playerInstance.won = true;
            }
        }
        
        DrawTexture(BocksImage, (int)Bocks.x, (int)Bocks.y, WHITE);
        DrawTexture(BocksEnemyImage, (int)BocksEnemy.x, (int)BocksEnemy.y, WHITE);
        DrawTexture(BocksEnemyPetImage, (int)bocksEnemyPet.x, (int)bocksEnemyPet.y, WHITE);

        DrawFPS(1800,50);

        if(playerInstance.died == true)
        {
            if(playerInstance.won == false)
            {
                DrawText("YOU DIED",500,500,150,RED);
            }
        }
        if(playerInstance.won == true)
        {
            if(playerInstance.died ==false)
            {
                DrawText("YOU WON",500,500,150,GREEN);
            }
        }
       
        if(GameStuff.START == true)
        {
            DrawText("START?",700,400,100,GREEN);
            DrawText("PRESS THE ENTER KEY",400,500,100,GREEN);
            
        } 

        if(IsKeyDown(KEY_ENTER))
        {
            GameStuff.START = false;
            
        }

        EndDrawing();
    }

    UnloadTexture(BocksEnemyPetImage);
    UnloadTexture(BocksEnemyImage);
    UnloadTexture(BocksImage);
    CloseWindow();

    return 0;
}