#include "raylib.h"
#include <iostream>
#include "player.h"
#include "game.h"
#include <vector>
#include "platform.h"

void player::PlayerMovement(Vector2 &Bocks, Texture2D BocksImage, float deltaTime,const Rectangle& platformCollision)
{
    timer++;
    
    game GameStuff;
    
    allowMoveLeft = true;
    allowMoveRight = true;
    allowMoveUp = true;
    allowMoveDown = true;
          
    // std::cout << GameStuff.collided;

    if (CheckCollisionRecs({ Bocks.x, Bocks.y, (float)BocksImage.width, (float)BocksImage.height }, platformCollision))
    {
        if (Bocks.x + BocksImage.width >= platformCollision.x && Bocks.x <= platformCollision.x + platformCollision.width)
        {
            if (IsKeyDown(KEY_A)) {
                if (Bocks.x > platformCollision.x) {
                    allowMoveLeft = false;
                }
            }
            if (IsKeyDown(KEY_D)) {
                if (Bocks.x < platformCollision.x + platformCollision.width) {
                    allowMoveRight = false;
                }
            }
        }
        
        if (Bocks.y + BocksImage.height >= platformCollision.y && Bocks.y <= platformCollision.y + platformCollision.height)
        {
            if (IsKeyDown(KEY_W)) {
                if (Bocks.y > platformCollision.y) {
                    allowMoveUp = false;
                }
            }
            if (IsKeyDown(KEY_S)) {
                if (Bocks.y < platformCollision.y + platformCollision.height) {
                    allowMoveDown = false;
                }
            }
        }
    }
    
    if(won == false && died == false)
    {
    if (IsKeyDown(KEY_A) && allowMoveLeft) {
    Bocks.x -= speedPlayer;
    }
    if (IsKeyDown(KEY_D) && allowMoveRight) {
        Bocks.x += speedPlayer;
    }
    if (IsKeyDown(KEY_W) && allowMoveUp) {
        Bocks.y -= speedPlayer;
    }
    if (IsKeyDown(KEY_S) && allowMoveDown) {
        Bocks.y += speedPlayer;
    }
    }
   
  
    
}

