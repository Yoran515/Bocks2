#include "raylib.h"
#include <iostream>
#include "player.h"
#include "game.h"


void player::PlayerMovement(Vector2 &Mokey, Texture2D MokeySize, float deltaTime)
{
    timer++;

    game GameStuff;

    if (timer > 3000)
    {
        std::cout << Mokey.y << std::endl;;
        timer = 0;
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


    if (!IsKeyDown(KEY_SPACE))
    {
        if (Ongroud == false)
        {
            Mokey.y += gravity;
            isJumping = false;
        }
    }
    if (Ongroud == true)
    {
        isJumping = false;
    }
    if (Mokey.y <= 500)
    {
        Ongroud = true;
    }
    if (IsKeyDown(KEY_SPACE))
    {
        if (Ongroud == true)
        {
            isJumping = true;
        }
    }

    if (isJumping == true)
    {
        if (Ongroud == true)
        {
            Mokey.y -= JumpForce * deltaTime;
            JumpForce -= gravity * deltaTime;
        }
        Ongroud = false;

    }
}