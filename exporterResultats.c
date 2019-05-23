#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void exporterResultats(int points, int nombreReponsesJustes, int nombreQuestions){

    FILE* fichier = NULL;


      fichier = fopen("Resultats.txt", "w+");


        if (fichier != NULL)
    {
    fprintf(fichier, "Vous avez eu juste a %d questions sur un total de %d questions", nombreReponsesJustes, nombreQuestions);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible de creer correctement le fichier");
    }



}
