#pragma once

#include <stddef.h>
typedef struct {
    int x;
} Escape;

typedef struct {
    Escape *arr;
    size_t n;
} ListaEscapes;

ListaEscapes NewListaEscapes(size_t n);
void FreeListaEscapes(ListaEscapes *lexits);
Escape *MejorEscape(ListaEscapes *lexits, int x);
