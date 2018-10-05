#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "afiches.h"
int initAfiches(afiches* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for (int i = 0; i <= limite; i++)
		{
			pArray[i].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}
int addAfiches (afiches* pArray,int limite, int id ,int *idMostrarAfiches)
{
	int retorno = -1;
	int i;
	//23int bufferIdClientes;
	int cantidadAfiches;
	char bufferNombreAfiche[51];
	char bufferZona[51];
    __fpurge(stdin);
	if(pArray != NULL && limite > 0)
	{
		for (i = 0; i<limite; i++ )
		{
			if (pArray[i].isEmpty == 0 &&
                //utn_getEntero(&bufferIdClientes, 10, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                utn_getEntero(&cantidadAfiches, 10, "Ingrese cantidad de afiches \n","cantidad invalida \n", 3) == 0 &&
				utn_getNombre( bufferNombreAfiche, 51, "Ingresar nombre de afiche\n","No es un nombre valido\n", 3) == 0 &&
				utn_getNombre( bufferZona, 51, "Ingresar zona\n","No es una zona valido\n", 3) == 0)
			{
				pArray[i].idAfiches = i;
				*idMostrarAfiches = i;
				pArray[i].cantidadAfiches = cantidadAfiches;
				strncpy(pArray[i].nombreDeAfiche, bufferNombreAfiche, 51);
				strncpy(pArray[i].zona, bufferZona, 15);
				pArray[i].idCliente = id;
				pArray[i].isEmpty =  1;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
* \brief    Toma la cadena e imprime lo que tenga guardado
* \param pArray Recibe el array ingresado
* \param limite Es el tamano maximo del string
*/
void printAfiches(afiches* pArray, int len)
{
      if (pArray != NULL && len > 0)
      {
      	for (int i =0; i< len; i++ )
		{
			if(pArray[i].isEmpty == 1)
            {
                printf("Id %d\n", pArray[i].idAfiches);
                printf("cantidad de afiches %d\n", pArray[i].cantidadAfiches);
                printf("nombre de afiche  %s\n", pArray[i].nombreDeAfiche);
                printf("zona %s\n", pArray[i].zona);
                printf("estado %s\n", pArray[i].estado);
                printf("Sector %d\n", pArray[i].idCliente);
                printf("---------------------------------\n");
            }
        }
      }
}
int afic_PorIDprintAfiches(afiches* pArray, int len, int *devID)
{
    int retorno = -1;
    int bufferIdVenta;
      if (pArray != NULL && len > 0)
      {
			if(utn_getEntero(&bufferIdVenta, 10, "Ingrese id de venta \n","No es un id valido \n", 3) == 0 &&
                pArray[bufferIdVenta].isEmpty == 1 )
            {
                printf("Id %d\n", pArray[bufferIdVenta].idAfiches);
                printf("cantidad de afiches %d\n", pArray[bufferIdVenta].cantidadAfiches);
                printf("nombre de afiche  %s\n", pArray[bufferIdVenta].nombreDeAfiche);
                printf("zona %s\n", pArray[bufferIdVenta].zona);
                printf("estado %s\n", pArray[bufferIdVenta].estado);
                printf("id Cliente %d\n", pArray[bufferIdVenta].idCliente);
                printf("---------------------------------\n");
                *devID = bufferIdVenta;
                retorno = 0;
            }
      }
    return retorno;
}
/**
* \brief    Toma la cadena y evalua si es un nombre
* \return En caso de exito retorna 0, si no -1
*/
int afi_modificarAfiches(afiches* pArray, int len, int id)
{
    int retorno = -1;
    int bufferCantidadAfiches;
    char bufferZona[51];
    if(pArray != NULL && len > 0 && len>0 && id >= 0 && id < len )
    {
        if (pArray[id].isEmpty == 1 &&
            utn_getEntero(&bufferCantidadAfiches, 8, "Modifique la cantidad de afiches \n","Cantidad invalido \n", 3) == 0 &&
            utn_getNombre( bufferZona, 51, "Modifique zona\n","No es una zona valido\n", 3) == 0)
        {
            pArray[id].cantidadAfiches = bufferCantidadAfiches;
            strncpy(pArray[id].zona, bufferZona, 51);
            strncpy(pArray[id].estado,"No cobrado", 51);
            printf("cliente modicado\n");
            retorno = 0;
        }else
        {
            printf("No existe id\n");
        }
    }
return retorno;
}


