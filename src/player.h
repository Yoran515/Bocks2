
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h" 
#include <vector>

class player
{
private:
    /* data */
public:
  
  float timer = 0;
  bool Onground; 
  float speedPlayer = 10.0f;
  float gravity = 0.001f;
  float JumpForce = 0.1f;
  bool isJumping;

  bool Looking_Left= false;
  bool Looking_Right= false;
  
  bool Falling;
  void PlayerMovement(Vector2 &Bocks, Texture2D BocksImage, float deltaTime,const Rectangle& platformCollision);

  bool Able_to_Dash = true;
  bool DashingUp = false;
  bool DashingDown = false;
  bool DashingLEFT = false;
  bool DashingRIGHT = false;
  float DashTime = 0.0f;
  float Dashspeed = 0.1f;
  bool collided = false;

  
  bool allowMoveLeft = true;
  bool allowMoveRight = true;
  bool allowMoveUp = true;
  bool allowMoveDown = true;

  bool died =false;
  bool won = false;
};
#endif