#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "afiches.h"
/* brief inicializa el array en 0 para verificar que esten vacios
*
*/
int initClientes(clientes* pArray, int limite)
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
/*
nt idClientes;
    char nombre[51];
    char apellidos[51];
    char cuit[15];
    int isEmpty;

*/
int addClientes (clientes* pArray,int limite, int* id)
{
	int retorno = -1;
	int i;
	char bufferNombre[51];
	char bufferApellido[51];
	char bufferCuit[15];
    __fpurge(stdin);
	if(pArray != NULL && limite > 0)
	{
		for (i = 0; i<limite; i++ )
		{
			if (pArray[i].isEmpty == 0 &&
				utn_getNombre( bufferNombre, 51, "Ingresar nombre de cliente\n","No es un nombre valido\n", 3) == 0 &&
				utn_getNombre( bufferApellido, 51, "Ingresar apellido de cliente\n","No es un apellido valido\n", 3) == 0 &&
				utn_getLetrasYNumeros(bufferCuit, 51,"Ingresar cuit de cliente\n") == 0)
			{
				pArray[i].idClientes = i;
				*id = pArray[i].idClientes;
				strncpy(pArray[i].nombre, bufferNombre, 51);
				strncpy(pArray[i].apellidos, bufferApellido, 51);
				strncpy(pArray[i].cuit, bufferCuit, 15);
				pArray[i].isEmpty =  1;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
* \brief    Toma la cadena y evalua si es un nombre
* \return En caso de exito retorna 0, si no -1
*/
int cli_modificarCliente(clientes* pArray, int len, int id)
{
    int retorno = -1;
    char bufferNombre[51];
    char bufferApellido[51];
    char bufferCuit[15];
    if(pArray != NULL && len > 0 && len>0 && id >= 0 && id < len )
    {
        if (pArray[id].isEmpty == 1 &&
            utn_getNombre(bufferNombre, 51, "Modifique Nombre\n", "No es un nombre valido\n", 2)==0 &&
            utn_getNombre( bufferApellido, 51, "Modifique apellido del cliente\n","No es un apellido valido\n", 3) == 0 &&
            utn_getLetrasYNumeros(bufferCuit, 15,"modificar cuit de cliente\n") == 0)
        {
            strncpy(pArray[id].nombre, bufferNombre, 51);
            strncpy(pArray[id].apellidos, bufferApellido, 51);
            strncpy(pArray[id].cuit, bufferCuit, 15);
            printf("cliente modicado\n");
            retorno = 0;
        }else
        {
            printf("No existe id\n");
        }
    }
return retorno;
}
/**
* \brief    evalua el id ingresado y en caso de exito y de haber informacion en ese id
*           borra la informacion
* \param pArray Recibe el array ingresado
* \param id es el numero a buscar
* \param limite Es el tamano maximo del string
*/
int cli_borrarCliente(clientes* pArray, int len, int id)
{
	int retorno = -1;
	char resp;
    if(pArray != NULL && len > 0 && len>0 && id >= 0 )
	{
		if (pArray[id].isEmpty == 1)
		{
			 printf("Esa seguro de borrar al cliente Y/N");
			 scanf("%c", &resp);
			 if (resp == 'Y')
			 {
                pArray[id].isEmpty = 0;
                retorno = 0;
			 }
			 else
			 {
                retorno = 1;
			 }
		}else
		{
			printf("No hay empleado con ese id\n");
		}
	}
  return retorno;
}
int printClientesAfiches(clientes* pArray, int limite)
{
   int i;
   int retorno;
   int idClintes;
    if(pArray != NULL && limite > 0)
    {
        for(i= 0; i< limite; i++)
        {
            if(pArray[i].isEmpty == 1)
            {
                printf("id %d\n", pArray[i].idClientes);
                printf("id %s\n", pArray[i].nombre);
                printf("id %s\n", pArray[i].apellidos);
                printf("id %s\n", pArray[i].cuit);
                retorno = 0;
            }
        }
    }
    return retorno;
}
/** \brief inicializa el array en 0 para verificar que esten vacios
*
*/
int mostarMenu(clientes * pArray, int limite,afiches* pArrayAfic, int limiteAfi)
{
    int retorno = -1;
    int resp;
    char resp2;
    int bufferID, idMostrarAfiches;
    int modificarCliente, borrarCliente,idVenta,idVentaprint;
    do
    {
        printf("1- Alta cliente\n");
        printf("2- Modificar cliente\n");
        printf("3- baja cliente\n");
        printf("4- Ingrese ventas\n");
        printf("5- Editar ventas\n");
        printf("6- Cobrar ventas\n");
        printf("7- imprimir clientes\n");
        printf("8- Salir\n");

        __fpurge(stdin);
        scanf("%d", &resp);
        switch(resp)
        {
            case 1:
            if(addClientes (pArray, limite, &bufferID) == 0)
            {
                printf("clientes ingresado, id %d\n", bufferID);
            }
            break;
            case 2:
            __fpurge(stdin);
            if (utn_getEntero(&modificarCliente, 10, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                         cli_modificarCliente( pArray, limite, modificarCliente) == 0)
            {
                printf("Cliente Modificado");
            }
            break;
            case 3:
            __fpurge(stdin);
            if (utn_getEntero(&borrarCliente, 10, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                cli_borrarCliente(pArray, limite, borrarCliente) == 0)
                {
                    printf("cliente Borrado");
                    break;
                }else if (utn_getEntero(&borrarCliente, 10, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                            cli_borrarCliente(pArray, limite, borrarCliente) == 1)
                            {
                                printf("No se borro Cliente");
                                break;
                            }
            case 4:
            __fpurge(stdin);
            if(utn_getEntero(&idVenta, 10, "Ingrese id de cliente\n","No es un id valido \n", 3) == 0 &&
                pArray[idVenta].isEmpty == 1 && addAfiches(pArrayAfic, limiteAfi, idVenta, &idMostrarAfiches) == 0)
                {
                    printf("venta ingresada, id %d\n", idMostrarAfiches);
                }
                break;
            case 5:
            printAfiches(pArrayAfic, limiteAfi);
            if(utn_getEntero(&idVenta, 10, "Ingrese id de venta\n","No es un id valido \n", 3) == 0 &&
                afi_modificarAfiches(pArrayAfic, limiteAfi, idVenta)== 0)
                {
                    printf("Venta modificada");
                }
            case 6:
            __fpurge(stdin);
            printAfiches(pArrayAfic, limiteAfi);
            if(afic_PorIDprintAfiches(pArrayAfic, limiteAfi, &idVentaprint) == 0)
            {
                printf("Desea cambiar el estado de la venta Y/N\n");
                scanf("%c", &resp2);
                if (resp2 == 'Y')
                {
                    strncpy(pArrayAfic[idVentaprint].estado,"cobrada" ,51);
                    printf("Estado : Cobrada\n");
                }
            }else
            {
                printf("no existe id\n");
            }
            break;
            case 7:
             printClientesAfiches(pArray, limite);
            break;
            case 8:
            printf("salio");
            retorno = 0;
            break;
      }

    }while(resp != 8);
 return retorno;
}
