#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include <string.h>
#include "struct.h"
#include "nbQuestions.h"
#include "execution.h"
#include "lectureFichier.h"
#include "Creation_exercice.h"

int main()
{
    int sortie=0,choix;

    printf("\nTapez 0 pour lancer la creation d'exercice");
    scanf("%d",&choix);
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
