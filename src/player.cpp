#include "raylib.h"
#include <iostream>


float speedPlayer = 0.2f;
int gravity = 1200;
float JumpForce = 600.0f;
bool isJumping;

bool Falling;

public class Player()
{
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
            if(Ongroud = false)
            {
                texture.y += gravity;
                isJumping = false;
            }
        }
        if(Ongroud == true)
        {
              isJumping = false;
        }
        if(texture.y <= 500)
        {
            Ongroud = true;
        }
        if(IsKeyDown(KEY_SPACE))
        {
            if(Ongroud == true)
            {
                isJumping = true;
            }
        }

        if(isJumping==true)
        {
            if(Ongroud ==true)
            {
                texture.y -= JumpForce * GetFrameTime();
                JumpForce -= gravity * GetFrameTime();
                
            }
           Ongroud = false;
        }
}