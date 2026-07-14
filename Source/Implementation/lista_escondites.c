#include <lista_escondites.h>
#include <stdlib.h>

ListaEscondites NewListaEscondites(size_t cant) {
    ListaEscondites le;
    le.arr = calloc(cant, sizeof(*le.arr));
    le.cantidad = cant;
    return le;
}

void FreeListaEscondites(ListaEscondites *le) { free(le->arr); }
