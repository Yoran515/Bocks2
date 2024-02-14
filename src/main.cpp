#include "raylib.h"
#include <iostream>

constexpr auto SCREEN_WIDTH  = 1600;
constexpr auto SCREEN_HEIGHT = 1000;

float speedPlayer = 0.2f;
float gravity = 0.1f;
float JumpForce = 0.1f;
const int groundYPos = (3 * SCREEN_HEIGHT) / 4;
bool isJumping;
float timer = 0;
bool Falling;


int main()
{
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    // SetTargetFPS(60);
    Vector2 texture = { (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2 };
    Texture2D textureSize = LoadTexture("assets/76b145443102d24bc171fa78703da365.png");

    float deltaTime = GetFrameTime();

    while (!WindowShouldClose())
    {
       
        BeginDrawing();
        if(texture.x < SCREEN_WIDTH - textureSize.width)
        {
            if(IsKeyDown(KEY_D))
            {
                texture.x += speedPlayer;
            }
        }
        if(texture.x > 0)
        {
            if(IsKeyDown(KEY_A))
            {
                texture.x -= speedPlayer;
            }
        }
        if(!IsKeyDown(KEY_SPACE))
        {
            if(!isJumping == true)
            {   
            
                if(texture.y < SCREEN_HEIGHT - textureSize.height)
                {
                    texture.y += gravity;
                }

            }
        }
        if(IsKeyDown(KEY_SPACE))
        {
            if(texture.y > 0)
            {
                isJumping = true;
            }
        }
        if(isJumping==true)
        {
           texture.y -= JumpForce;
           timer+= deltaTime;

            if(timer > 1)
            {
                Falling = true;
                timer = 0;
                isJumping =false;
            }
        }
        if(Falling ==true)
        {
             texture.y += gravity;
        }

        ClearBackground(RAYWHITE);
        
        // const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        // const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        DrawTexture(textureSize, texture.x, texture.y, WHITE);
        
        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, text_size.y + textureSize.height + text_size.y + 10, 20, BLACK);
        EndDrawing();
    }
    UnloadTexture(textureSize);   
    CloseWindow();

    return 0;
}
