/*int pedirIndiceVacio(char* pArray, int len, int * indice);
{
    int retorno = -1;
     for (int i = 0; i <= len; i++)
     {
       if (pArray[i].flag == 0)
       {
         *indice = i;
         retorno = 0;
         break;
       }
     }
     printf("Indice vacio %d\n", *indice);

     return retorno;
}

int inicializarArray(char* pBuffer,int limite)
{
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i]=1;
    }
    return 0;
}

int existeID(char* pBuffer,int limite,int ID)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].id==ID&&pBuffer[i].isEmpty==0){
            retorno=0;
        }
    }
    return retorno;

}
int ingresoForzado(Pantalla pBuffer,int limite,char* nombre,char*direccion,char* tipo,float precio)
{
    int aux;
    buscarIndiceVacio(pBuffer,limite,&aux);
    strncpy(pBuffer[aux].nombre,nombre);
    strncpy(pBuffer[aux].tipo,tipo);
    strncpy(pBuffer[aux].direccion,direccion,);
    pBuffer[aux].ID=obtenerID();
    pBuffer[aux].isEmpty=0;
    pBuffer[aux].precio=precio;
    return 0;
}
int pan_obtenerID()
{
    static int ID=0;
    return ID++;

}

int busquedaPorID(pantalla* pBuffer,int limite,int ID,int* id)
{
    int i;
    int retorno=-1;
    for (i=0;i<limite;i++){
        if(pBuffer[i].id.ID==ID&& pBuffer[i].isEmpty==0)
            {
            *id=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}*/
/*int array_calcularNumeroMaximo(int *pArray,int limite,int *maximo)
{
    int auxMax;
    int i;
    int retorno=-1;
    if(pArray!= NULL && limite>0)
    {
        retorno=0;
        for (i=0;i<limite;i++)
        {
            if(i==0)
            {
                auxMax=pArray[i];
            }else if(pArray[i]>auxMax)
            {
                auxMax = *(pArray+i);
            }
        }
    }
    *maximo=auxMax;
    return retorno;
}*/
/*void printProducto(empleadoDes* pArray, int len)
{
      if (pArray != NULL && len > 0)
      {
      	for (int i =0; i< len; i++ )
		{
			if(pArray[i].isEmpty == 1)
            {
                printf("Id %d\n", pArray[i].id);
                printf("Nombre %s\n", pArray[i].name);
                printf("apellido %s\n", pArray[i].lastName);
                printf("Salario %f\n", pArray[i].salary);
                printf("Sector %d\n", pArray[i].sector);
                printf("---------------------------------\n");                }
        }
      }
}*/
/**
* \brief    evalua el id ingresado y en caso de exito te permite
*           modificar la informacion
* \param pArray Recibe el array ingresado
* \param id es el numero a buscar
* \param limite Es el tamano maximo del string
*/
/*int getEmpleadoModificar(empleadoDes* pArray, int len, int id)
{
    int retorno = -1;
    int resp;
    char bufferNombre[51];
    char bufferApellido[51];
    float bufferSalario;
    int bufferSector;
    if(pArray != NULL && len > 0 && len>0 && id >= 0 && id < len )
    {
        if (pArray[id].isEmpty == 1)
        {
            printf("\n Desea modificar : \n 1-Nombre: \n 2-Apellido: \n 3-Salario: \n 4 Sector: \n 5-Salir \n");
            scanf("%d",&resp);
            switch(resp)
            {
                case 1:
                if (utn_getNombre(bufferNombre, 51, "Modifique Nombre\n", "No es un nombre valido\n", 2)==0)
                {
                    strncpy(pArray[id].name, bufferNombre, 51);
                    printf("Nombre modicado\n");
                    break;
                }
                case 2:
                if (utn_getNombre( bufferApellido, 51, "Modifique apellido del Empleado\n","No es un apellido valido\n", 3) == 0)
                {
                    strncpy(pArray[id].lastName, bufferApellido, 51);
                    printf("Apellido modicado\n");
                    break;
                }
                case 3:
                if (utn_getFloat(&bufferSalario,20, "Modifique Salario\n", "No es un precio valido\n",2 )== 0)
                {
                    pArray[id].salary =  bufferSalario;
                    printf("Salario modicado\n");
                    break;
                }
                case 4:
                if (utn_getEntero( &bufferSector , 20, "Modifique numero de Sector\n", "No es un sector valido\n", 3) == 0)
                {
                    pArray[id].sector =  bufferSector;
                    printf("Sector modicado\n");
                    break;
                }
                default :
                printf("Opcion no valida\n");
            }
            retorno = 0;
        }else
        {
            printf("No existe id\n");
        }
    }
return retorno;
}*/
/**
* \brief    evalua el id ingresado y en caso de exito y de haber informacion en ese id
*           borra la informacion
* \param pArray Recibe el array ingresado
* \param id es el numero a buscar
* \param limite Es el tamano maximo del string
*/
/*int borrarEmpleado(empleadoDes* pArray, int len, int id)
{
	int retorno = -1;
    if(pArray != NULL && len > 0 && len>0 && id >= 0 )
	{
		if (pArray[id].isEmpty == 1)
		{
			 pArray[id].isEmpty = 0;
			 retorno = 0;
		}else
		{
			printf("No hay empleado con ese id\n");
		}
	}
  return retorno;
}*/
/**
* \brief    calcula el total y el promedio sobre el salario,
*           y muestra cuales empleados superan ese promedio.
* \param pArray Recibe el array ingresado
* \param limite Es el tamano maximo del string
*/
/*void getTotalPromedio(empleadoDes* pArray, int len)
{
	int i, j;
	float acumuladorSalario = 0;
	int contadorSuperan = 0;
    int contador = 0;
	if(pArray != NULL && len > 0 && len>0 )
	{
		for (i =0; i< len; i++ )
		{
			if(pArray[i].isEmpty == 1)
			{
				acumuladorSalario = acumuladorSalario + pArray[i].salary;
				contador++;
			}
		}
		if (acumuladorSalario > 0)
		{
			printf("el total es %f\n", acumuladorSalario);
			printf("El promedio es %f\n", acumuladorSalario/contador);
		}
		for (j =0; j< len; j++)
		{
			if (pArray[j].isEmpty == 1 && pArray[j].salary > (acumuladorSalario/contador))
			{
				printf("Id: %d\n", pArray[j].id);
				printf("Nombre: %s\n", pArray[j].name);
				printf("Apellido: %s\n ", pArray[j].lastName);
				printf("Salario: %f\n", pArray[j].salary);
				printf("Sector: %d\n", pArray[j].sector);
				printf("------------------------------------\n");
				contadorSuperan++;
				fflush(stdin);
			}
		}
		printf("la cantidad que superan el promedio %d\n", contadorSuperan);
	}
}*/
/**
* \brief    recibe una cadena y evalua si son datos validos,
*           en caso de exito agrega un empleado
* \param pArray Recibe el array ingresado
* \param limite Es el tamano maximo del string
*/
/*int addEmployees (empleadoDes* pArray,int limite)
{
	int retorno = -1;
	int i;
	char ingEmpleado;
	char bufferNombre[51];
	char bufferApellido[51];
	float bufferSalario;
	int bufferSector;
	if(pArray != NULL && limite > 0)
	{
		for (i = 0; i<limite; i++ )
		{
			if (pArray[i].isEmpty == 0 &&
				utn_getNombre( bufferNombre, limite, "Ingresar nombre de Empleado\n","No es un nombre valido", 3) == 0 &&
				utn_getNombre( bufferApellido, limite, "Ingresar apellido de Empleado\n","No es un apellido valido", 3) == 0 &&
				utn_getFloat( &bufferSalario, limite, "Ingrese Salario\n", "No es un salario valido", 3) == 0 &&
				utn_getEntero( &bufferSector , limite, "Ingresar numero de Sector\n", "No es un sector valido", 3) == 0)
			{
				pArray[i].id = i;
				strncpy(pArray[i].name, bufferNombre, 51);
				strncpy(pArray[i].lastName, bufferApellido, 51);
				pArray[i].salary =  bufferSalario;
				pArray[i].sector = bufferSector;
				pArray[i].isEmpty =  1;
				retorno = 0;
				printf("Desea ingresar otro empleado? Y/N\n");
				scanf("%c", &ingEmpleado);
				if (ingEmpleado == 'N')
				{
					break;
				}else if (ingEmpleado == 'Y')
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
}*/
/**
* \brief    recibe una cadena y ordena en primer caso por apellido
*           en caso de ser iguales por sector
* \param pArray Recibe el array ingresado
* \param limite Es el tamano maximo del string
* \param upOrDonw es el orden en cual se va mostar en caso de 1 es de mayor a menor si es 0 lo contrario
*/
/*int con_ordenarByNombre(empleadoDes* pBuffer,int limite,int upOrDonw)
{
  int i, j;
  int auxId;
  char auxNombre[50];
  char auxLastName[50];
  int auxSector;
  float auxSalario;
  if (pBuffer != NULL && limite > 0 && (upOrDonw == 0 || upOrDonw == 1))
    {
        for(i = 0; i < limite; i++)
        {
          j = i + 1;
                fflush(stdin);
                if(pBuffer[i].isEmpty == 1&& pBuffer[j].isEmpty == 1 && upOrDonw == 1 && strcmp(pBuffer[i].lastName,pBuffer[j].lastName) >0
                   || (strcmp(pBuffer[i].lastName,pBuffer[j].lastName) ==0 && pBuffer[i].sector > pBuffer[j].sector))
                {
                    auxId = pBuffer[j].id;
                    pBuffer[j].id = pBuffer[i].id;
                    pBuffer[i].id = auxId;

                    strncpy(auxLastName, pBuffer[j].lastName, 50);
                    strncpy(pBuffer[j].lastName,pBuffer[i].lastName, 50);
                    strncpy(pBuffer[i].lastName,auxLastName, 50);

                    strncpy(auxNombre, pBuffer[j].name, 50);
                    strncpy(pBuffer[j].name,pBuffer[i].name, 50);
                    strncpy(pBuffer[i].name,auxNombre, 50);

                    auxSalario = pBuffer[j].salary;
                    pBuffer[j].salary = pBuffer[i].salary;
                    pBuffer[i].salary = auxSalario;

                    auxSector = pBuffer[j].sector;
                    pBuffer[j].sector = pBuffer[i].sector;
                    pBuffer[i].sector = auxSector;
                }else if(pBuffer[i].isEmpty == 1&& pBuffer[j].isEmpty == 1 && upOrDonw == 0 && strcmp(pBuffer[i].lastName,pBuffer[j].lastName) <0
                         || strcmp(pBuffer[i].lastName,pBuffer[j].lastName) ==0 && pBuffer[i].sector < pBuffer[j].sector)
                {
                    auxId = pBuffer[j].id;
                    pBuffer[j].id = pBuffer[i].id;
                    pBuffer[i].id = auxId;

                    strncpy(auxLastName, pBuffer[j].lastName, 50);
                    strncpy(pBuffer[i+1].lastName,pBuffer[i].lastName, 50);
                    strncpy(pBuffer[i].lastName,auxLastName, 50);

                    strncpy(auxNombre, pBuffer[j].name, 50);
                    strncpy(pBuffer[i+1].name,pBuffer[i].name, 50);
                    strncpy(pBuffer[i].name,auxNombre, 50);

                    auxSalario = pBuffer[j].salary;
                    pBuffer[j].salary = pBuffer[i].salary;
                    pBuffer[i].salary = auxSalario;

                    auxSector = pBuffer[j].sector;
                    pBuffer[j].sector = pBuffer[i].sector;
                    pBuffer[i].sector = auxSector;
                }
        }
    }
    return 1;
}*/
