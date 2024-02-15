#include "raylib.h"
#include <iostream>

constexpr auto SCREEN_WIDTH  = 1000;
constexpr auto SCREEN_HEIGHT = 1000;

float timer = 0;

bool Ongroud;

int Banana_Amount = 0;

int main()
{
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    // SetTargetFPS(60);
    Vector2 texture = { (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2 };
    Texture2D textureSize = LoadTexture("assets/Mokey.png");
    
    float deltaTime = GetFrameTime();

    while (!WindowShouldClose())
    {
        timer++;

        if(timer >3000){
        std::cout <<Ongroud;
        std::cout <<" ";
        timer = 0;
        }
      
        
        BeginDrawing();
        // if(texture.x < SCREEN_WIDTH - textureSize.width)
        // {
        //     if(IsKeyDown(KEY_D))
        //     {
        //         texture.x += speedPlayer;
        //     }
        // }
        // if(texture.x > 0)
        // {
        //     if(IsKeyDown(KEY_A))
        //     {
        //         texture.x -= speedPlayer;
                
        //     }
        // }
        // if(!IsKeyDown(KEY_SPACE))
        // { 
        //     if(Ongroud = false)
        //     {
        //         texture.y += gravity;
        //         isJumping = false;
        //     }
        // }
        // if(Ongroud == true){
        //       isJumping = false;
        // }
        // if(texture.y <= 500)
        // {
        //     Ongroud = true;
        // }
        // if(IsKeyDown(KEY_SPACE))
        // {
        //     if(Ongroud == true)
        //     {
        //         isJumping = true;
        //     }
        // }

        // if(isJumping==true)
        // {
        //     if(Ongroud ==true)
        //     {
        //         texture.y -= JumpForce * GetFrameTime();
        //         JumpForce -= gravity * GetFrameTime();
                
        //     }
        //    Ongroud = false;
        // }

        ClearBackground(RAYWHITE);
        
        DrawTexture(textureSize, texture.x, texture.y, WHITE);
        
        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, text_size.y + textureSize.height + text_size.y + 10, 20, BLACK);

        const char* Banana = "banANA!: "+ Banana_Amount;
        const Vector2 Banana_size = MeasureTextEx(GetFontDefault(), Banana, 20, 1);
        DrawText(Banana+Banana_Amount, 500,700 + Banana_size.y + 10, 20, DARKBLUE);

        EndDrawing();
    }
    UnloadTexture(textureSize);   
    CloseWindow();

    return 0;
}
