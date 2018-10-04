#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int utn_getString(char* pBuffer, int limite);
int isValidMail(char *pBuffer, int limite);
int utn_getEmial(char *pBuffer,int limite,char* msj,char*msjError,int reintentos);
int utn_isValidNombre(char* pBuffer,int limite);
int isValidFloat(char *pBuffer, int limite);
int isValidEntero(char *pBuffer, int limite);
int utn_getFloat( float *pFloat, int limite, char *mensaje,char *mensajeError, int reintentos);
int utn_getEntero( int *pEntero, int limite, char *mensaje,char *mensajeError, int reintentos);
int utn_getLetrasYNumeros(char* pBuffer,int limite,char* msj);
int getString(char* pBuffer, int limite);
#endif // UTN_H_INCLUDED
