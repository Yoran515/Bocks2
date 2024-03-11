#ifndef GAME_H
#define GAME_H

#include "raylib.h" 
#include "platform.h" 
#include <vector>
#include "player.h"

class game
{
private:
    /* data */
public:
  
int SCREEN_WIDTH  = 1020;
int SCREEN_HEIGHT = 1000;

float timer = 0;

bool Ongroud;
int Banana_Amount = 0;

    std::vector<platform>platforms;
    player Player;
    // Method to initialize platforms
    void InitializePlatforms()
    {
        platforms.push_back(platform(100, 800 - 100, 550, 100));
        platforms.push_back(platform(400, 400 - 100, 550, 100));
        
        // Add more platforms as needed
    }

    void CheckCollision(player& playerInstance, Texture2D MokeyImage, Vector2& Mokey)
    {
        Rectangle playerRect = { Mokey.x, Mokey.y, MokeyImage.width, MokeyImage.height };

        for (const auto& platform : platforms)
        {
            if (CheckCollisionRecs(playerRect, platform.rect))
            {
                
                if(Player.Falling)
                {
                    playerInstance.Onground = true;
                    playerInstance.isJumping = false;
                    std::cout << "Standing" << std::endl;;
                }
                Mokey.y = platform.rect.y - MokeyImage.height;
            }
            else 
            {
                Player.Falling = true;
                std::cout << "NotStanding" << std::endl;;
            }
        }
    }
};
#endif