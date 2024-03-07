
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h" 


class player
{
private:
    /* data */
public:
  
    float timer = 0;
    bool Ongroud; 
    float speedPlayer = 0.2f;
    int gravity = 1200;
    float JumpForce = 600.0f;
    bool isJumping;

    
    bool Falling;
  void PlayerMovement(Vector2 &Mokey, Texture2D MokeySize, float deltaTime);
};
#endif
