#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "pantalla.h"
#include "contratacion.h"

typedef struct
{
    int idContrataciones;
    char cliente;
    int cantidadDias;
    int idPantalla;
    int isEmpty;
}contracionesDes;


#endif // CONTRATACION_H_INCLUDED
