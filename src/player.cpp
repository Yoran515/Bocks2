#include "raylib.h"
#include <iostream>
#include "player.h"
#include "game.h"


void player::PlayerMovement(Vector2 &Mokey, Texture2D MokeySize, float deltaTime)
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
    if (IsKeyDown(KEY_D) && Mokey.x < GameStuff.SCREEN_WIDTH - MokeySize.width)
    {
        // Mokey.x += speedPlayer * deltaTime;
        Mokey.x += speedPlayer;
        
    }

    if (IsKeyDown(KEY_A) && Mokey.x > 0)
    {
       Mokey.x -= speedPlayer;
    }

    
    if (IsKeyDown(KEY_SPACE) && Onground)
    {
        isJumping = true;
        Onground = false;
        JumpForce = 1.0f; 
    }
   
    if (!IsKeyDown(KEY_SPACE) && Onground)
    {
        isJumping = false;
    }

    if (isJumping)
    {
        Mokey.y -= JumpForce;
        JumpForce -= gravity;

       
        if (Mokey.y >= GameStuff.SCREEN_HEIGHT - MokeySize.height)
        {
            Mokey.y = GameStuff.SCREEN_HEIGHT - MokeySize.height; 
            isJumping = false;
            Onground = true;
            JumpForce = 0.0f;
        }
    }
    
    else
    {
        // Apply gravity when not jumping
        if (Mokey.y < GameStuff.SCREEN_HEIGHT - MokeySize.height)
        {
            Mokey.y += gravity;
        }
        else
        {
            Mokey.y = GameStuff.SCREEN_HEIGHT - MokeySize.height;
            Onground = true;
        }
    }
    if(JumpForce < 0)
    {
        Falling = true;
    }
}