#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "pantalla.h"
#include "contratacion.h"
int initContrataciones(contracionesDes* pArray,int limite)
{
    int i;
    int retorno =-1;
    if(pArray != NULL && limite >0)
    {
        for(i=0; i< limite; i++)
        {
            pArray[i].isEmpty = 0;
        }
        retorno = 0;
    }
  return retorno;
}
/*
*
*
*
**/
int con_addContrataciones (contracionesDes* pArray,int limite)
{
	int retorno = -1;
	int i;
	int bufferID;
	char ingPantalla;
	char bufferNombre[51];
	char bufferDireccion[51];
	char bufferTipo[51];
	float bufferPrecio;
	if(pArray != NULL && limite > 0)
	{
		for (i = 0; i<limite; i++ )
		{
			if (pArray[i].isEmpty == 0 &&
				utn_getNombre( bufferNombre, limite, "Ingresar Nombre\n","No es un nombre valido", 3) == 0 &&
				utn_getNombre( bufferDireccion, limite, "Ingresar direccion\n","No es una direccion valida", 3) == 0 &&
                utn_getNombre( bufferTipo, 51, "Modifique tipo de pantalla\n","No es un tipo de pantalla valido\n", 3) == 0 &&
				utn_getFloat( &bufferPrecio, limite, "Ingrese precio\n", "No es un precio valido", 3) == 0)
			{
				pArray[i].id = i;
				strncpy(pArray[i].nombre, bufferNombre, 51);
				strncpy(pArray[i].direccion, bufferDireccion, 51);
				pArray[i].precio =  bufferPrecio;
				pArray[i].isEmpty =  1;
				retorno = 0;
				printf("Desea ingresar otra pantalla? Y/N\n");
				scanf("%c", &ingPantalla);
				if (ingPantalla == 'N')
				{
					break;
				}else if (ingPantalla == 'Y')
				{
					continue;
				}else
				{
					printf("No es una opcion valida\n");
					break;
				}
			}
		}
	}
	return retorno;
}

/**
*
*
*
**/
void mostrarMenuContrataciones(contracionesDes* pArray, int limite)
{
    if (pArray != NULL && limite >0 )
    {


    }
}
