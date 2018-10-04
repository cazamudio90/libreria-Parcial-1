#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
/**
* \brief El usuario ingresa una cadena con fgets
* \param pBuffer Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/
int utn_getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[4096];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        //__fpurge(stdin);
        fflush(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}
/**
* \brief Valida que se una mail
* \param pBuffer Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/
int isValidFloat(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (((pBuffer[0] == '-' || pBuffer[0] == '+') && pBuffer[1] != '.') ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }
            else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Evalua si es un nombre valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*/
 int utn_isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief Evalua si se trata de un entero
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
int isValidEntero(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (pBuffer[0] == '-' || pBuffer[0] == '+' ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief Evalua si se trata de un mail(acepta letras numeros '.' '_' antes del @ y letras '.' despues)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
int isValidMail(char *pBuffer, int limite)
{
    int retorno = 0;
    int contadorDeArrobas = 0;
    int contadorDePuntosTrasArroba = 0;
    int flagLetraIntroducida = 0;
    int i;
    if( pBuffer != NULL && limite > 0 &&
        tolower(pBuffer[0]) >= 'a' &&
        tolower(pBuffer[0]) <= 'z')
    {
        retorno = 1;
        flagLetraIntroducida = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if( (tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z' ) ||
                (pBuffer[i] >= '0' && tolower(pBuffer[i]) <= '9' && contadorDeArrobas == 0))
            {
                flagLetraIntroducida = 1;
            }
            else if(pBuffer[i] == '@' && contadorDeArrobas == 0 && flagLetraIntroducida == 1)
            {
                contadorDeArrobas++;
                flagLetraIntroducida = 0;
            }
            else if(pBuffer[i] == '.' && flagLetraIntroducida == 1)
            {
                flagLetraIntroducida = 0;
                if(contadorDeArrobas == 1)
                {
                    contadorDePuntosTrasArroba++;
                }
            }
            else if(pBuffer[i] == '_' && flagLetraIntroducida == 1 && contadorDeArrobas == 0)
            {
                flagLetraIntroducida = 0;
            }
            else
            {
                retorno = 0;
                break;
            }
        }
    }
    if(retorno == 1 && contadorDeArrobas == 1 && contadorDePuntosTrasArroba > 0)
    {
        retorno = 1;
    }
    else
    {
        printf("\nejemplo_123@mail.com.ar");
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Toma la cadena y evalua si es un float en caso de exito lo transforma a float
* \param pFloat Recibe el numero ingresado en caso de exito
* \param limite Es el tamano maximo de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*/
int utn_getFloat(   float *pFloat, int limite, char *mensaje,char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL &&mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( utn_getString(bufferFloat, limite) == 0 &&
                isValidFloat(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
int utn_getEntero(  int *pEntero, int limite, char *mensaje,char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferEntero[4096];
    if( pEntero != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( utn_getString(bufferEntero, limite) == 0 &&
                isValidEntero(bufferEntero, limite))
            {
                *pEntero = atoi(bufferEntero);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/* brief funcion que pide uun email y valida si esta bien devuelvo 0
* param cadena
*
*/
int utn_getEmial(char *pArray,int limite,char* msj,char*msjError,int reintentos)
{
    int retorno=-1;
    if(pArray!=NULL && limite >0 && reintentos >=0)
    {
        do{
            reintentos--;
            printf("%s",msj);
            if(utn_getString(pArray,limite)==0 && isValidMail(pArray, limite)==1)
            {
                //strncpy(pArray,buffer,limite);
                retorno=0;
                break;
            }else
                printf("%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}
