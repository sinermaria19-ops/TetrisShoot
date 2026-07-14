#pragma once

#include <collision.h>
#include <dibujo.h>
#include <raylib.h>
#include <stddef.h>
typedef struct {
    Vector2 coordenadas;
    CollisionBox colisiones;
    Dibujo *dib;
} Enemigo;

void Enemigo_Avanzar(Enemigo *e, int velocidad, float frame_time);

void Enemigo_DibujarVarios(Enemigo *e, size_t cantidad);
