#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "afiches.h"
/*** \brief Funcion que muestra los clientes con la menor
           cantidad de ventas a cobrar si el flag es 0
           y si es 1, la cantidad de ventas cobradas
**\param arrayAfi array de afiches a recorrer
**\param limiteAfi limite maximo que tiene el arrayAfi
**\param pArray array de clientes a recorrer
**\param limite maximo que tiene el pArray
**\param flag flag utilizado para diferenciar que tipo de ventas se quiere obtener
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_clienteConMasVentas(afiches* arrayAfi, int limiteAfi, clientes* pArray, int limite, int flag)
{
    int retorno = -1;
    int i, j;
    int auxVentasPorClienteAcobrar[limite];
    int auxVentasPorClienteCobradas[limite];
    int menorCantidadAcobrar;
    int menorCantidadCobradas;
    int contadorDeVentasACobrar;
    int contadorDeVentasCobradas;
    if(arrayAfi != NULL && limiteAfi >0 && pArray != NULL && limite > 0 && (flag == 0 || flag == 1))
    {
        for(i=0; i< limite; i++)
        {
            if(pArray[i].isEmpty == 1)
            {
                contadorDeVentasACobrar = 0;
                contadorDeVentasCobradas = 0;
                for(j=0; j < limiteAfi; j++)
                {
                    if( flag == 0 && arrayAfi[j].isEmpty == 1 && arrayAfi[j].idCliente == pArray[i].idClientes &&
                        strcmp(arrayAfi[j].estado, "a cobrar") == 0)
                    {
                        contadorDeVentasACobrar++;
                    }else if ( flag == 1 && arrayAfi[j].isEmpty == 1 && arrayAfi[j].idCliente == pArray[i].idClientes &&
                                strcmp(arrayAfi[j].estado, "cobrada")== 0)
                    {
                        contadorDeVentasCobradas++;
                    }
                }
                auxVentasPorClienteAcobrar[i] = contadorDeVentasACobrar;
                auxVentasPorClienteCobradas[i] = contadorDeVentasCobradas;
                if ((auxVentasPorClienteAcobrar[i] < menorCantidadAcobrar || i == 0)
                    && strcmp(arrayAfi[i].estado, "a cobrar") == 0&& flag ==0 )
                {
                    menorCantidadAcobrar = auxVentasPorClienteAcobrar[i];
                }else if ((auxVentasPorClienteCobradas[i] < menorCantidadCobradas || i == 0) && flag ==1)
                {
                    menorCantidadCobradas = auxVentasPorClienteCobradas[i];
                }
            }
        }
        for(i=0; i < limite; i++)
        {
            if( (flag == 0 && pArray[i].isEmpty == 1 && menorCantidadAcobrar == auxVentasPorClienteAcobrar[i])||
                  (flag == 1 && pArray[i].isEmpty == 1 && menorCantidadCobradas == auxVentasPorClienteCobradas[i]))
                {
                    printf("ID : %d \n",pArray[i].idClientes);
                    printf("Nombre : %s \n",pArray[i].nombre);
                    printf("apellido : %s \n",pArray[i].apellidos);
                    printf("Cuit : %s \n",pArray[i].cuit);
                    printf("---------------------\n");
                }
        }
     retorno = 0;
    }
    return retorno;
}
/*** \brief Funcion que muestra el clientes con la menor
           cantidad de ventas
**\param arrayAfic array de afiches a recorrer
**\param limiteAfic limite maximo que tiene el arrayAfi
**\param pArray array de clientes a recorrer
**\param limite maximo que tiene el pArray
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_clientesConMenosVentas(afiches* pArrayAfic, int limiteAfic, clientes * pArray, int limite)
{
    int retorno = -1;
    int i,j,auxID;
    int contadorDeVentas;
    int clienteConMenosVentas;
    int clientesVentas[limite];
    if (pArrayAfic != NULL && limiteAfic >0 && pArray != NULL && limite > 0)
    {
        for (i=0 ; i < limite; i++ )
        {
            contadorDeVentas = 0;
            if (pArray[i].isEmpty == 1)
            {
                 for(j=0; j < limiteAfic; j++)
                 {
                    if (pArrayAfic[j].isEmpty == 1 && pArrayAfic[j].idCliente == pArray[i].idClientes)
                    {
                        contadorDeVentas++;
                    }
                 }
                 clientesVentas[i] = contadorDeVentas;
                 if(clientesVentas[i] < clienteConMenosVentas || i == 0)
                 {
                     clienteConMenosVentas = clientesVentas[i];
                     auxID = pArray[i].idClientes;
                 }
            }

         }
         for (i=0; i< limite; i++)
         {
             if (pArray[i].idClientes == auxID)
             {
                 cliente_mostrar(pArray,limite,auxID);
                 break;
             }
         }
        retorno = 0;
    }


    return retorno;
}
/*** \brief Funcion que muestra la zona con mas cantidad de afiches
**\param arrayAfic array de afiches a recorrer
**\param limiteAfic limite maximo que tiene el arrayAfic
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_zonaConMasAfiches(afiches *pArrayAfic, int limiteAfic)
{
    int retorno = -1;
    int i,j;
    int contadorCaba, zonaCaba;
    int contadorZonaSur, zonaSur = 0;
    int contadorZonaOeste, zonaOeste = 0;
    int zonaConMasAfichesCaba[limiteAfic];
    int zonaConMasAfichesSur[limiteAfic];
    int zonaConMasAfichesOeste[limiteAfic];
    if(pArrayAfic != NULL && limiteAfic > 0)
    {
        for (i=0; i< limiteAfic; i++)
        {
            if (pArrayAfic[i].isEmpty == 1)
            {
                contadorCaba = 0;
                contadorZonaSur = 0;
                contadorZonaOeste = 0;
                for (j = 0; j< limiteAfic; j++)
                {
                    if( pArrayAfic[j].isEmpty == 1 && strcmp(pArrayAfic[j].zona, "CABA") == 0 )
                    {
                        contadorCaba = contadorCaba + pArrayAfic[j].cantidadAfiches;
                    }else if (pArrayAfic[j].isEmpty == 1 && strcmp(pArrayAfic[j].zona, "ZONA SUR") == 0 )
                    {
                        contadorZonaSur = contadorZonaSur + pArrayAfic[j].cantidadAfiches;
                    }else if (pArrayAfic[j].isEmpty == 1 && strcmp(pArrayAfic[j].zona, "ZONA OESTE") == 0 )
                    {
                        contadorZonaOeste = contadorZonaOeste + pArrayAfic[j].cantidadAfiches;
                    }
                }
                zonaConMasAfichesCaba[i] = contadorCaba;
                zonaConMasAfichesSur[i] = contadorZonaSur;
                zonaConMasAfichesOeste[i] = contadorZonaOeste;
                if (zonaConMasAfichesCaba[i] > zonaCaba || i==0)
                {
                    zonaCaba = zonaConMasAfichesCaba[i];
                }else if (zonaConMasAfichesSur[i] > zonaSur || i == 0)
                {
                    zonaSur = zonaConMasAfichesSur[i];
                }else if (zonaConMasAfichesOeste[i] > zonaOeste || i== 0)
                {
                    zonaOeste = zonaConMasAfichesOeste[i];
                }
            }
        }
        if (zonaCaba > zonaSur && zonaCaba > zonaOeste)
            {
                printf("La zona con mas afiches: CABA\n");
            }else if (zonaSur > zonaCaba && zonaSur > zonaOeste)
            {
                printf("La zona con mas afiches: ZONA SUR\n");
            }else if (zonaOeste > zonaCaba && zonaOeste > zonaSur)
            {
                printf("La zona con mas afiches: ZONA Oeste\n");
            }
        retorno = 0;
    }
    return retorno;
}
/*** \brief Funcion que muestra el cliente que compro
            menos afiches
**\param arrayAfic array de afiches a recorrer
**\param limiteAfic limite maximo que tiene el arrayAfic
**\param pArray array de clientes a recorrer
**\param limite maximo que tiene el pArray
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_clienteConMenosAfiches(afiches * pArrayAfic, int limiteAfic, clientes * pArray, int limite)
{
    int retorno = -1;
    int i,j, auxID;
    int acumuladorDeAfiches;
    int clienteConMasAfiches[limite];
    int clientesConMenosAfiches;
    if (pArrayAfic != NULL && limiteAfic > 0 && pArray != NULL && limite > 0)
    {
        for (i= 0; i< limite; i++)
        {
            if(pArray[i].isEmpty == 1)
            {
                acumuladorDeAfiches = 0;
                for(j=0; j< limiteAfic; j++)
                {
                    if(pArrayAfic[j].isEmpty == 1 && pArrayAfic[j].idCliente == pArray[i].idClientes)
                    {
                        acumuladorDeAfiches = acumuladorDeAfiches + pArrayAfic[j].cantidadAfiches;
                    }
                }
                clienteConMasAfiches[i] = acumuladorDeAfiches;
            }
            if((clienteConMasAfiches[i] < clientesConMenosAfiches || i == 0) && pArray[i].isEmpty==1)
            {
                clientesConMenosAfiches = clienteConMasAfiches[i];
                auxID = pArray[i].idClientes;
            }
        }
        for(i= 0; i < limite; i++)
        {
            if(pArray[i].idClientes == auxID)
            {
                cliente_mostrar(pArray, limite, auxID);
                break;
            }
        }
        retorno = 0;
    }

    return retorno;
}
/*** \brief Funcion que muestra el cliente con mas
            afiches a cobrar
**\param arrayAfi array de afiches a recorrer
**\param limiteAfi limite maximo que tiene el arrayAfi
**\param pArray array de clientes a recorrer
**\param limite maximo que tiene el pArray
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_clienteConMasAfichesAcobrar(afiches * pArrayAfic, int limiteAfic, clientes * pArray, int limite)
{
    int retorno = -1;
    int i,j, auxID;
    int acumuladorDeAfiches;
    int clienteConMasAfiches[limite];
    int clientesConMenosAfiches;
    if (pArrayAfic != NULL && limiteAfic > 0 && pArray != NULL && limite > 0)
    {
        for (i= 0; i< limite; i++)
        {
            if(pArray[i].isEmpty == 1)
            {
                acumuladorDeAfiches = 0;
                for(j=0; j< limiteAfic; j++)
                {
                    if(pArrayAfic[j].isEmpty == 1 && pArrayAfic[j].idCliente == pArray[i].idClientes && strcmp(pArrayAfic[j].estado,"a cobrar")==0)
                    {
                        acumuladorDeAfiches = acumuladorDeAfiches + pArrayAfic[j].cantidadAfiches;
                    }
                }
                clienteConMasAfiches[i] = acumuladorDeAfiches;
            }
            if((clienteConMasAfiches[i] > clientesConMenosAfiches || i == 0) && pArray[i].isEmpty==1)
            {
                clientesConMenosAfiches = clienteConMasAfiches[i];
                auxID = pArray[i].idClientes;
            }
        }
        for(i= 0; i < limite; i++)
        {
            if(pArray[i].idClientes == auxID)
            {
                cliente_mostrar(pArray, limite, auxID);
                break;
            }
        }
        retorno = 0;
    }
    return retorno;
}
/*** \brief Funcion que muestra la cantidad de clientes
            que superan la compra de mas de 500 afiches
**\param pArrayAfi array de afiches a recorrer
**\param limiteAfi limite maximo que tiene el arrayAfi
**\param pArray array de clientes a recorrer
**\param limite maximo que tiene el pArray
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_cantidadClientesMayores500(clientes* pArray, int limite, afiches* pArrayAfi, int limiteAfi)
{
    int retorno = -1;
    int i, j;
    int acumuladorAfiches;
    int arrayMayores500[limite];
    int contadorMayores500 = 0;
    if (pArrayAfi != NULL && limiteAfi > 0 && pArray != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            if(pArray[i].isEmpty == 1)
            {
                acumuladorAfiches = 0;
                for(j=0; j< limite; j++)
                {
                    if(pArrayAfi[j].isEmpty == 1 && pArrayAfi[j].idCliente == pArray[i].idClientes)
                    {
                        acumuladorAfiches = acumuladorAfiches + pArrayAfi[j].cantidadAfiches;
                    }
                }
                arrayMayores500[i] = acumuladorAfiches;
                if (arrayMayores500[i] > 500)
                {
                    contadorMayores500++;
                }
            }
        }
        printf("cantidad de clientes que superan los 500 afiches: %d\n", contadorMayores500);
        retorno = 0;
    }

    return retorno;
}
/*** \brief Funcion que muestra la cantidad de afiches
            vendidos por zona
**\param arrayAfi array de afiches a recorrer
**\param limiteAfi limite maximo que tiene el arrayAfi
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_cantidadAfichesPorZona(afiches* pArrayAfic, int limiteAfic)
{
    int retorno = -1;
    int i;
    int acumuladorCaba = 0;
    int acumuladorZonaSur = 0;
    int acumuladorZonaOeste = 0;
    if(pArrayAfic != NULL && limiteAfic > 0)
    {
        for (i = 0; i< limiteAfic; i++)
        {
            if (pArrayAfic[i].isEmpty == 1 && strcmp(pArrayAfic[i].zona, "CABA")==0)
            {
                acumuladorCaba = acumuladorCaba + pArrayAfic[i].cantidadAfiches;
            }else if (pArrayAfic[i].isEmpty == 1 && strcmp(pArrayAfic[i].zona, "ZONA SUR")==0)
            {
                acumuladorZonaSur = acumuladorZonaSur + pArrayAfic[i].cantidadAfiches;
            }else if (pArrayAfic[i].isEmpty == 1 && strcmp(pArrayAfic[i].zona, "ZONA OESTE")==0)
            {
                acumuladorZonaOeste = acumuladorZonaOeste + pArrayAfic[i].cantidadAfiches;
            }

        }
        printf("Cantidad de afiches vendidos en CABA: %d\n", acumuladorCaba);
        printf("Cantidad de afiches vendidos en ZONA SUR: %d\n", acumuladorZonaSur);
        printf("Cantidad de afiches vendidos en ZONA OESTE: %d\n", acumuladorZonaOeste);
    }
    return retorno;
}
/*** \brief Funcion que muestra el promedio de afiches
            vendidos por clientes
**\param arrayAfic array de afiches a recorrer
**\param limiteAfic limite maximo que tiene el arrayAfi
**\param pArray array de clientes a recorrer
**\param limite maximo que tiene el pArray
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_promedioAfichesCliente(clientes * pArray, int limite, afiches*pArrayAfic, int limiteAfic)
{
 int retorno = -1;
 int i,j;
 int acumuladorAfiches = 0;
 int contadorClientes = 0;
 float promedio;
 if (pArray != NULL && limite >0 && pArrayAfic != NULL && limite > 0)
 {
     for(i=0; i< limite; i++)
     {
         if(pArray[i].isEmpty == 1)
         {
             for(j=0; j< limiteAfic; j++)
             {
                if(pArrayAfic[j].isEmpty== 1 && pArray[i].idClientes == pArrayAfic[j].idCliente)
                {
                    acumuladorAfiches = acumuladorAfiches + pArrayAfic[j].cantidadAfiches;
                    contadorClientes++;
                }
             }
         }
     }
     if(contadorClientes > 0)
     {
         promedio = acumuladorAfiches / contadorClientes;
         printf("El promedio por clientes de afiches es: %f\n", promedio);
         retorno = 0;
     }
 }
 return retorno;
}
/*** \brief Funcion que lista las ventas por zona,
            1° CABA, 2° ZONA SUR, 3° ZONA OESTE
**\param arrayAfic array de afiches a recorrer
**\param limiteAfic limite maximo que tiene el arrayAfic
**\return retorna 0 si la funcion esta bien sino -1
***/
int informar_listarVentasPorZona(afiches* pArrayAfic, int limiteAfic)
{
    int retorno = -1;
    int i,j,m;
    int auxId;
    if (pArrayAfic != NULL && limiteAfic >0)
    {
        printf("CABA\n");
        printf("-----------------------------------------\n");
        for(i= 0; i< limiteAfic; i++)
        {
            if(pArrayAfic[i].isEmpty == 1 && strcmp(pArrayAfic[i].zona, "CABA")== 0)
            {
                auxId = pArrayAfic[i].idAfiches;
                printAfichesPorID(pArrayAfic, limiteAfic, auxId);
            }
        }
        printf("ZONA OESTE\n");
        printf("-----------------------------------------\n");
        for (m=0; m< limiteAfic; m++)
        {
            if(pArrayAfic[m].isEmpty == 1 && strcmp(pArrayAfic[m].zona,"ZONA OESTE")==0)
            {
                printAfichesPorID(pArrayAfic,limiteAfic,pArrayAfic[m].idAfiches);
            }
        }
        printf("ZONA SUR\n");
        printf("-----------------------------------------\n");
        for (j=0; j< limiteAfic; j++)
        {
            if(pArrayAfic[j].isEmpty == 1 && strcmp(pArrayAfic[j].zona,"ZONA SUR")==0)
            {
                printAfichesPorID(pArrayAfic,limiteAfic,pArrayAfic[j].idAfiches);
            }
        }
        retorno = 0;
    }
    return retorno;
}


