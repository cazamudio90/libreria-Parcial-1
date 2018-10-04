#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
int main()
{
    char email[51];
    if (utn_getEmial(email,51,"ingrese Email\n", "email no valido\n", 3) == 0)
    {
        printf("email valido");
    }
    return 0;
}
