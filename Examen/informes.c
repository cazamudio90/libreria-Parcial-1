/*int informes_ordenarByNombre(empleadoDes* pBuffer,int limite,int upOrDonw)
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
}
*/
