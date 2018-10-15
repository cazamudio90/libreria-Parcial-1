#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "pantalla.h"
#include "contratacion.h"

#define CANTIDAD_PANTALLA 51
#define CANTIDAD_CONTRATACIONES 51
int main()
{
    pantallaDes ingresoPantalla[CANTIDAD_PANTALLA];
    contracionesDes ingresoContrataciones[CANTIDAD_CONTRATACIONES];
    initPantalla(ingresoPantalla, CANTIDAD_PANTALLA);
    initContrataciones(ingresoContrataciones,CANTIDAD_CONTRATACIONES);
    mostrarMenu (ingresoPantalla, CANTIDAD_PANTALLA);
    return 0;
}
