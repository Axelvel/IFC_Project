#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"

void inscription(char nom_eleve[])
{   int i=0;

    //On demande � l'�l�ve son nom et son pr�nom une premi�re fois
    do{
    memset(nom_eleve, 0, strlen(nom_eleve));
    printf("Entrez votre nom et pr�nom sous ce format : NOMPRENOM\n");
    viderBuffer();
    scanf("%s",nom_eleve);

    }
    while(((nom_eleve[i]<65||nom_eleve[i]>90))==1);

}
