#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"

void inscription(char nom_eleve[])
{
    //VARIABLES
    int i,verif=0;

    //DEBUT
    do{
    verif=0;
    memset(nom_eleve, 0, strlen(nom_eleve));
    printf("Entrez votre nom et prénom sous ce format : NOMPRENOM\n");
    scanf("%s",nom_eleve);
    viderBuffer();

    for(i=0;i<strlen(nom_eleve);i++)
    {
        if((nom_eleve[i]<65||nom_eleve[i]>90))
        {
            verif++;
        }
    }

    }
    while(verif!=0);

}
