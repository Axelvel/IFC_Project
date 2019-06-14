#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifNumeric(char chaine[])
{
    //VARIABLES
    int i,verif=0;

    //DEBUT
    for(i=0;i<strlen(chaine);i++)
    {
        if((chaine[i]<49)||(chaine[i]>57))
        {
            verif++;
        }
    }

    return verif;
}
