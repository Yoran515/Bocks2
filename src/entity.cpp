#include "raylib.h"
#include <iostream>
#include "game.h"
#include "entity.h"

    
void entity::Entity()
{    
  
    DrawTexture(BocksImage, (int)Bocks.x, (int)Bocks.y, WHITE);
    UnloadTexture(BocksImage);
}