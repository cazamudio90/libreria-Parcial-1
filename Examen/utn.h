#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
int utn_getEntero(  int *pEntero, int limite, char *mensaje,char *mensajeError, int reintentos);
int utn_getFloat(   float *pFloat, int limite, char *mensaje,char *mensajeError, int reintentos);
int utn_getNombre(  char* pNombre,int limite, char* msg, char* msgErr, int reintentos);
int utn_getString(char* pBuffer, int limite);
int isValidEntero(char *pBuffer, int limite);
int utn_isValidNombre(char* pBuffer,int limite);
int isValidFloat(char *pBuffer, int limite);

#endif // UTN_H_INCLUDED
