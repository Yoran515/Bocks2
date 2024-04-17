#ifndef PLATFORM_H
#define PLATFORM_H

#include "raylib.h" 


class platform
{
public:
  Rectangle rect;

    platform(float x, float y, float width, float height)
    {
        rect = { x, y, width, height };
    }
    
    

    void Draw() const
    {
        DrawRectangleRec(rect, BLUE);
    }
};
#endif
