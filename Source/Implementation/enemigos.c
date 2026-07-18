#include <enemigos.h>
#include <escape.h>
#include <raymath.h>
#include <screen.h>
#include <stddef.h>

void Enemigo_Update(Enemigo *e, float now, float frame_time) {
    Vector2 obj;
    switch (e->estado) {
    case ENEM_STATE_NULL:
        e->esperar_hasta = now + GetRandomValue(2000, 6000) / 1000.;
        e->estado = ENEM_STATE_INACTIVO;
        break;
    case ENEM_STATE_INACTIVO:
        if (now > e->esperar_hasta) {
            e->esc = PrimerEsconditeLibre(e->le);
            if (e->esc == NULL)
                break;

            e->objetivo =
                Vector2Add(e->esc->zona_escondida, e->esc->coordinates);
            e->coordenadas.x = e->objetivo.x;
            e->esc->ocupado = true;
            e->estado = ENEM_STATE_CORRIENDO_Y;
        }
        break;
    case ENEM_STATE_CORRIENDO_X:
        obj = e->objetivo;
        obj.y = e->coordenadas.y;

        e->coordenadas =
            Vector2MoveTowards(e->coordenadas, obj, e->velocidad * frame_time);

        if (Vector2Equals(e->coordenadas, obj))
            e->estado = ENEM_STATE_CORRIENDO_Y;

        break;
    case ENEM_STATE_CORRIENDO_Y:
        obj = e->objetivo;
        obj.x = e->coordenadas.x;

        e->coordenadas =
            Vector2MoveTowards(e->coordenadas, obj, e->velocidad * frame_time);

        if (Vector2Equals(e->coordenadas, obj)) {
            e->estado = ENEM_STATE_ESCONDIDO;
            e->esperar_hasta = now + GetRandomValue(250, 3500) / 1000.;
        }
        break;
    case ENEM_STATE_ESCONDIDO:
        if (now > e->esperar_hasta) {
            Escondite *esc = SiguienteEscondite(e->le, e->coordenadas);
            if (esc) {
                e->esc->ocupado = false;
                e->esc = esc;
                e->objetivo =
                    Vector2Add(e->esc->zona_escondida, e->esc->coordinates);
                e->esc->ocupado = true;
                e->estado = ENEM_STATE_CORRIENDO_X;
                break;
            }

            Escape *exit = MejorEscape(e->lexits, e->coordenadas.x);
            if (exit) {
                e->esc->ocupado = false;
                e->esc = NULL;
                e->objetivo = (Vector2){
                    .x = exit->x,
                    .y = SCREEN_SHOOTER_HEIGHT + 200,
                };
                e->estado = ENEM_STATE_CORRIENDO_X;
                break;
            }
        }
        break;
    case ENEM_STATE_OUT:
        break;
    }
}

void Enemigo_Reset(Enemigo *e) {
    e->estado = ENEM_STATE_INACTIVO;
    e->coordenadas.y = -100;
    if (e->esc)
        e->esc->ocupado = false;
    e->velocidad = GetRandomValue(110, 200);
}
