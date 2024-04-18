#ifndef GAME_H
#define GAME_H

#include "raylib.h" 
#include "platform.h" 
#include <vector>
#include "player.h"

class game
{
    private:
 
    public:
    
    int SCREEN_WIDTH  = 1920;
    int SCREEN_HEIGHT = 1080;

    float timer = 0;
    bool START= true;
    bool Ongroud;
    int Banana_Amount = 0;

    std::vector<platform>platforms;
    player Player;

    bool collided = false; 

    void InitializePlatforms()
    {
    
    platforms.push_back(platform(100, 800 - 100, 100, 550));
    platforms.push_back(platform(100, 20 - 100, 100, 550));

    platforms.push_back(platform(1600, 800 - 100, 100, 550));
    platforms.push_back(platform(1600, 20 - 100, 100, 550));
    
    platforms.push_back(platform(0, 100 - 100, 2080, 100));
    platforms.push_back(platform(0, (float)SCREEN_HEIGHT - 100, 2080, 100));

    }
};

#endif