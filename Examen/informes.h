#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "afiches.h"
int informar_clienteConMasVentas(afiches* arrayAfi, int limiteAfi, clientes* pArray, int limite, int flag);
int informar_clientesConMenosVentas(afiches* pArrayAfic, int limiteAfic, clientes * pArray, int limite);
int informar_zonaConMasAfiches(afiches *pArrayAfic, int limiteAfic);
int informar_clienteConMenosAfiches(afiches * pArrayAfic, int limiteAfic, clientes * pArray, int limite);
int informar_clienteConMasAfichesAcobrar(afiches * pArrayAfic, int limiteAfic, clientes * pArray, int limite);
int informar_cantidadClientesMayores500(clientes* pArray, int limite, afiches* pArrayAfi, int limiteAfi);
int informar_cantidadAfichesPorZona(afiches* pArrayAfic, int limiteAfic);
int informar_listarVentasPorZona(afiches* pArrayAfic, int limiteAfic);
int informar_promedioAfichesCliente(clientes * pArray, int limite, afiches*pArrayAfic, int limiteAfic);
#endif // INFORMES_H_INCLUDED
