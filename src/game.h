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
    
    int SCREEN_WIDTH  = 1920;
    int SCREEN_HEIGHT = 780;

    float timer = 0;

    bool Ongroud;
    int Banana_Amount = 0;

    std::vector<platform>platforms;
    player Player;

    
    // Method to initialize platforms
    void InitializePlatforms()
    {
        // platforms.push_back(platform(100, 800 - 100, 550, 100));
        // platforms.push_back(platform(400, 400 - 100, 550, 100));
        // platforms.push_back(platform(0, 1100 - 100, 2080, 100));
        // Add more platforms as needed
    }

    // void CheckCollision(player& playerInstance, Texture2D MokeyImage, Vector2& Mokey)
    // {
    //     Rectangle playerRect = { Mokey.x, Mokey.y, MokeyImage.width, MokeyImage.height };

    //     bool collided = false; 

    //     for (const auto& platform : platforms)
    //     {
    //         if (CheckCollisionRecs(playerRect, platform.rect))
    //         {
    //             collided = true; // Collision occurred
         
    //             if (Player.Falling && Mokey.y < platform.rect.y)
    //             {

    //                 // std::cout << "Standing" << std::endl;
    //                 playerInstance.Onground = true;
                    
    //                 playerInstance.isJumping = false;
                    
    //                 // Mokey.y = platform.rect.y - MokeyImage.height;
    //             }
            
    //         }
    //     }
        
    //     if (!collided)
    //     {
    //         // Player.JumpForce = 0.0f;
    //         // std::cout << "NotStanding" << std::endl;
           
    //         Player.Falling = true;
    //         Mokey.y += Player.JumpForce;
    //         // Mokey.y -= Player.gravity;
    //     }
    // }
};
#endif