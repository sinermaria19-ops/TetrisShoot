#pragma once
#include <escondite.h>
#include <stddef.h>

typedef struct {
    Escondite *arr;
    size_t cantidad;
} ListaEscondites;

ListaEscondites NewListaEscondites(size_t cant);
void FreeListaEscondites(ListaEscondites *le);
