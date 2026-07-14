#pragma once
#include <collision.h>
#include <raylib.h>

typedef struct {
    Texture texture;
    CollisionBox collision;
    Vector2 coordinates;
    Vector2 texture_offset;
} Escondite;
