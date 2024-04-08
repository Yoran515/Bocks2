#include "raylib.h"
#include <iostream>
#include "player.h"
#include "drawingplatform.h"


void player::PlayerMovement(Vector2 &Bocks, Texture2D BocksSize, float deltaTime)
{
    timer++;

    drawingplatform GameStuff;

    if (timer > 3000)
    {
        timer = 0;
    }
   
    if(GameStuff.collided == false)
    {
        if (IsKeyDown(KEY_D) && Bocks.x < GameStuff.SCREEN_WIDTH - BocksSize.width)
        {
            Bocks.x += speedPlayer; 
        }

        if (IsKeyDown(KEY_A) && Bocks.x > 0)
        {
            Bocks.x -= speedPlayer;
        }
        if (IsKeyDown(KEY_S) && Bocks.y < GameStuff.SCREEN_HEIGHT - BocksSize.height)
        {
            Bocks.y += speedPlayer; 
        }

        if (IsKeyDown(KEY_W) && Bocks.y > 0)
        {
            Bocks.y -= speedPlayer;
        } 
    }
}