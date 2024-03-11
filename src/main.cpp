#include "player.h"
#include "raylib.h"
#include <iostream>
#include "game.h"
#include "platform.h"

int main()
{
    
    player playerInstance;
    game GameStuff;

    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    GameStuff.InitializePlatforms();  // Initialize platforms

    Texture2D MokeyImage = LoadTexture("assets/Mokey.png");
    Vector2 Mokey = { static_cast<float>(GameStuff.SCREEN_WIDTH) / 2.0f, static_cast<float>(GameStuff.SCREEN_HEIGHT) - MokeyImage.height };

    float deltaTime = GetFrameTime();  // Get the time between frames
    GameStuff.timer = 0;
    while (!WindowShouldClose())
    {
        
        GameStuff.CheckCollision(playerInstance, MokeyImage, Mokey);
        for (const auto& platform : GameStuff.platforms)
        {
            platform.Draw();
        }
        
        playerInstance.PlayerMovement(Mokey, MokeyImage, deltaTime); 
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(MokeyImage, Mokey.x, Mokey.y, WHITE);
    
    // if (IsKeyDown(KEY_D))
    // {
    //     DrawTextureEx(MokeyImage, Mokey, 0.0f, 1.0f, WHITE); // No flip, draw as-is
    // }
    // if (IsKeyDown(KEY_A))
    // {
    //     DrawTextureEx(MokeyImage, Mokey, 0.0f, -1.0f, WHITE); // Flip with a scale factor of -1 on the x-axis
    // }
    
    EndDrawing();
    }

    UnloadTexture(MokeyImage);
    CloseWindow();

    return 0;
}