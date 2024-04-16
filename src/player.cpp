#include "raylib.h"
#include <iostream>
#include "player.h"
#include "game.h"


void player::PlayerMovement(Vector2 &Bocks, Texture2D BocksImage, float deltaTime)
{
    timer++;
    // std::cout <<Looking_Left << std::endl;;
    game GameStuff;

    if (timer > 3000)
    {
        // std::cout <<"Isjumping = " << isJumping << std::endl;;
        // std::cout <<"IsOnground = " << Onground << std::endl;;
       
        timer = 0;
    }

    
    if(IsKeyDown(KEY_A))
    {
        Looking_Left = true;
        Looking_Right = false ;
    }
    if(IsKeyDown(KEY_D))
    {
        Looking_Left = false;
        Looking_Right = true;
    }
    if (IsKeyDown(KEY_D) && Bocks.x < GameStuff.SCREEN_WIDTH - BocksImage.width)
    {
        // Mokey.x += speedPlayer * deltaTime;
        Bocks.x += speedPlayer; 
    }

    if (IsKeyDown(KEY_A) && Bocks.x > 0)
    {
       Bocks.x -= speedPlayer;
    }
    if (IsKeyDown(KEY_S) && Bocks.y < GameStuff.SCREEN_HEIGHT - BocksImage.height)
    {
        // Mokey.x += speedPlayer * deltaTime;
        Bocks.y += speedPlayer; 
    }

    if (IsKeyDown(KEY_W) && Bocks.y > 0)
    {
       Bocks.y -= speedPlayer;
    }
}