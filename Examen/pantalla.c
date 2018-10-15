#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "pantalla.h"
#include "contratacion.h"
int initPantalla(pantallaDes* pArray,int limite)
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
int pan_addPantalla (pantallaDes* pArray,int limite)
{
	int retorno = -1;
	int i;
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
* \brief    evalua el id ingresado y en caso de exito te permite
*           modificar la informacion
* \param pArray Recibe el array ingresado
* \param id es el numero a buscar
* \param limite Es el tamano maximo del string
*/
int utn_getEmpleadoModificar(pantallaDes* pArray, int len, int id)
{
    int retorno = -1;
    char bufferNombre[51];
    char bufferApellido[51];
    char bufferTipo[51];
    float bufferSalario;
    if(pArray != NULL && len > 0 && len>0 && id >= 0 && id < len )
    {
        if (pArray[id].isEmpty == 1 &&
            utn_getNombre(bufferNombre, 51, "Modifique Nombre\n", "No es un nombre valido\n", 2)==0&&
            utn_getNombre( bufferApellido, 51, "Modifique direccion\n","No es un direccion valida\n", 3) == 0 &&
            utn_getNombre( bufferTipo, 51, "Modifique tipo de pantalla\n","No es un tipo de pantalla valido\n", 3) == 0 &&
             utn_getFloat(&bufferSalario,20, "Modifique Precio\n", "No es un precio valido\n",2 )== 0)
            {
                strncpy(pArray[id].nombre, bufferNombre, 51);
                strncpy(pArray[id].direccion, bufferApellido, 51);
                pArray[id].precio =  bufferSalario;
                retorno = 0;
            }
        }else
        {
            printf("No existe id\n");
        }
return retorno;
}
int utn_borrarPantalla(pantallaDes* pArray, int len, int id)
{
    int retorno = -1;
    if(pArray != NULL && len > 0 && len>0 && id >= 0 && id < len )
    {
        if (pArray[id].isEmpty == 1 )
        {
            pArray[id].isEmpty = 0;
            retorno = 0;
        }
        }else
        {
            printf("No existe pantalla con ese id\n");
        }
return retorno;
}
/**
*
*
*
**/
int pan_imprimirListaPantalla(pantallaDes* pBuffer,int limite)
{
    int i;
    system("clear");
    for(i=0;i<limite;i++)
    {
        if(pBuffer[i].isEmpty==0)
        {
            printf("\nID: %d",pBuffer[i].id);
            printf("\tNombre: %s",pBuffer[i].nombre);
            printf("\tDescripcion: %s",pBuffer[i].direccion);
            printf("\tTipo: %s",pBuffer[i].tipo);
            printf("\tTipo: %.2f",pBuffer[i].precio);
        }
    }
    return 0;
}
/**
* \brief    muestra el menu principal del programa
* \param pArray Recibe el array ingresado
* \param limite Es el tamano maximo del string
*/
int mostrarMenu (pantallaDes* pArray, int limite)
{
	int retorno = -1;
	char resp;
	int i, flag =0;
	int bufferID;
	if (pArray != NULL && limite>0)
	{
		do
		{
			printf("a - Carga de pantalla\n");
			printf("b - Modificar de pantalla por id\n");
			printf("c - Baja de pantalla por id\n");
			printf("e - Salir\n");
            fflush(stdin);
			 //__fpurge(stdin);
			scanf("%c",&resp);
			switch(resp)
			{
				case 'a':
				if (pan_addPantalla(pArray, limite) == 0)
				{
				 printf("Pantalla cargada\n")	;
				 break;
				}
				break;
				case 'b':
				// modificar
				for (i = 0; i< limite ; i++)
                {
                  if (pArray[i].isEmpty == 1)
                  {
                    flag = 1;
                    break;
                   }
                }
                  if (flag == 0)
                  {
                      printf("No hay informacion cargada\n");
                  }
				if ( flag == 1 && utn_getEntero(&bufferID, limite, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                     utn_getEmpleadoModificar( pArray, limite, bufferID) == 0)
				{
					printf("Empleado Modificado\n");
					flag = 0;
					break;
				}
				break;
				case 'c':
				for (i = 0; i< limite ; i++)
                {
                  if (pArray[i].isEmpty == 1)
                  {
                    flag = 1;
                    break;
                   }
                }
                  if (flag == 0)
                  {
                      printf("No hay informacion cargada\n");
                  }
                    if ( flag == 1 && utn_getEntero(&bufferID, limite, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                         utn_borrarPantalla(pArray, limite, bufferID) == 0)
                    {
                        printf("Empleado Borrado\n");
                            flag = 0;
                        break;
                    }
                    break;
				case 'd':
                pan_imprimirListaPantalla(pArray,limite);
                if(utn_getEntero(&bufferID, limite, "\nIngrese Id para cargar su publicidad\n", "Id invalido\n", 3) == 0 )
                {
                    mostrarMenuContrataciones()
                }

				case 'e':
				printf("Salio");
				retorno = 0;
				break;
				default:
				printf("No es una opcion correcta\n");
				break;
			}
		}while(resp != 'e');
	}
	return retorno;
}
