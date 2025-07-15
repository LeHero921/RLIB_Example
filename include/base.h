#pragma once
#include <raylib.h>
#include <iostream>

extern bool glContext;

typedef struct Sprite
{
    Texture2D texture;
    Rectangle dest_rect;
} Sprite;
