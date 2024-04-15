#include "raylib.h"
#include <iostream>
#include "player.h"
#include "drawingplatform.h"


void player::PlayerMovement(Vector2 &Bocks, Texture2D BocksImage, float deltaTime)
{
    timer++;
    drawingplatform GameStuff;
    
    // BocksImage = LoadTexture("assets/Bockey.png");
    // Bocks = { (float)(GameStuff.SCREEN_WIDTH) / 2.0f, (float)(GameStuff.SCREEN_HEIGHT) - BocksImage.height };

    // Bocks.x = 500;
    // Bocks.y = 500;
  

    if (timer > 3000)
    {
        timer = 0;
    }
   
    if(GameStuff.collided == false)
    {
        if (IsKeyDown(KEY_D) && Bocks.x < GameStuff.SCREEN_WIDTH - BocksImage.width)
        {
            Bocks.x += speedPlayer; 
        }

        if (IsKeyDown(KEY_A) && Bocks.x > 0)
        {
            Bocks.x -= speedPlayer;
        }
        if (IsKeyDown(KEY_S) && Bocks.y < GameStuff.SCREEN_HEIGHT - BocksImage.height)
        {
            Bocks.y += speedPlayer; 
        }

        if (IsKeyDown(KEY_W) && Bocks.y > 0)
        {
            Bocks.y -= speedPlayer;
        } 
    }
    
 
}