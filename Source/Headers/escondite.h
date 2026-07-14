#pragma once
#include <collision.h>
#include <dibujo.h>
#include <raylib.h>

typedef struct {
    CollisionBox collision;
    Vector2 coordinates;
    Dibujo *dib;
} Escondite;
