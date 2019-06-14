#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include <string.h>
#include "struct.h"
#include "nbQuestions.h"
#include "execution.h"
#include "lectureFichier.h"
#include "Creation_exercice.h"
#include "conio.h"

int main()
{
    int sortie=0,choix;

    printf("\nTapez C pour lancer la creation d'exercice, sur n'importe quelle lettre pour acceder au exercices ");
    choix=getch();
    if(choix=='C')
    {
        Creation_exercice();
    }
    do
    {
        sortie=menu();
    }
    while(sortie!=1);



}
