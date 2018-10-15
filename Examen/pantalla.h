#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "pantalla.h"
#include "contratacion.h"
typedef struct
{
    int id;
    char nombre[51];
    char direccion[51];
    char tipo[51];
    float precio;
    int isEmpty;
}pantallaDes;
int initPantalla(pantallaDes* pArray,int limite);
int pan_addPantalla (pantallaDes* pArray,int limite);
int mostrarMenu (pantallaDes* pArray, int limite);
int utn_borrarPantalla(pantallaDes* pArray, int len, int id);
int utn_getEmpleadoModificar(pantallaDes* pArray, int len, int id);
pan_imprimirListaPantalla(pantallaDes* pBuffer,int limite);
#endif // PANTALLA_H_INCLUDED
