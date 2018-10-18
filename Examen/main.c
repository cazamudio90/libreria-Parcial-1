#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "afiches.h"
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_AFICHES 1000
int main()
{
    clientes clientesArray[CANTIDAD_CLIENTES];
    afiches aficheArray[CANTIDAD_AFICHES];
    initClientes(clientesArray, CANTIDAD_CLIENTES);
    initAfiches(aficheArray, CANTIDAD_AFICHES);

    cliente_ingresoForzado(clientesArray, CANTIDAD_CLIENTES, "carlos", "zamudio", "20-35127002-1");
    cliente_ingresoForzado(clientesArray, CANTIDAD_CLIENTES, "juan", "Romero", "20-12345678-9");
    cliente_ingresoForzado(clientesArray, CANTIDAD_CLIENTES, "christian", "salas", "25-87654321-7");

    afiches_ingresoForzado(aficheArray, CANTIDAD_AFICHES, 15, "imagenjpg", "CABA", 0, "a cobrar");
    afiches_ingresoForzado(aficheArray, CANTIDAD_AFICHES, 2000, "imagenjpg", "ZONA SUR", 1, "a cobrar");
    afiches_ingresoForzado(aficheArray, CANTIDAD_AFICHES, 200, "imagenjpg", "CABA", 0, "a cobrar");
    afiches_ingresoForzado(aficheArray, CANTIDAD_AFICHES, 25, "imagenjpg", "ZONA OESTE", 2, "a cobrar");
    afiches_ingresoForzado(aficheArray, CANTIDAD_AFICHES, 10, "imagenjpg", "CABA", 0, "a cobrar");


    //cliente_mostrar(clientesArray, CANTIDAD_CLIENTES);
    //printAfiches(aficheArray, CANTIDAD_AFICHES);
    mostarMenu(clientesArray, CANTIDAD_CLIENTES,aficheArray, CANTIDAD_AFICHES);
    return 0;
}
