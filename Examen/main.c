#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "afiches.h"
#define CANTIDAD_CLIENTES 100
int main()
{
    clientes clientesArray[CANTIDAD_CLIENTES];
    afiches aficheArray[CANTIDAD_CLIENTES];
    initClientes(clientesArray, CANTIDAD_CLIENTES);
    initAfiches(aficheArray, CANTIDAD_CLIENTES);
    mostarMenu(clientesArray, CANTIDAD_CLIENTES,aficheArray, CANTIDAD_CLIENTES);
    return 0;
}
