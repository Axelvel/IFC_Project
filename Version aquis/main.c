#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "menu.h"
#include "struct.h"
#include "Creation_exercice.h"

int main()
{
    //VARIABLES
    int sortie=0,choix;

    //DEBUT
    printf("\nTapez 0 pour lancer la creation d'exercice");
    scanf("%d",&choix);
    viderBuffer();

    if(choix==0)
    {
        Creation_exercice();
    }
    do
    {
        sortie=menu();
    }
    while(sortie!=1);



}
