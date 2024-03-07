#include "player.h"
#include "raylib.h"
#include <iostream>
#include "game.h"


int main()
{
    
    player playerInstance;
    game GameStuff;
    InitWindow(GameStuff.SCREEN_WIDTH, GameStuff.SCREEN_HEIGHT, "Window title");

    Vector2 Mokey = { static_cast<float>(GameStuff.SCREEN_WIDTH) / 2, static_cast<float>(GameStuff.SCREEN_HEIGHT) / 2 };
    Texture2D MokeyImage = LoadTexture("assets/Mokey.png");

    float deltaTime = GetFrameTime();  // Get the time between frames
    while (!WindowShouldClose())
    {
    
    playerInstance.PlayerMovement(Mokey, MokeyImage, deltaTime); // Pass Mokey by reference
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(MokeyImage, Mokey.x, Mokey.y, WHITE);
    EndDrawing();
    }

    UnloadTexture(MokeyImage);
    CloseWindow();

    return 0;
}