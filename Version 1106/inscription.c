#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"

void inscription(char nom_eleve[])
{   int i=0;
int verif=0;

    //On demande à l'élève son nom et son prénom une première fois
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
