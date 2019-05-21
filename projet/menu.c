#include <stdio.h>
#include <stdlib.h>
#include "comptageExercice.h"

int menu()
{
    char exos_dispos[100][25];
    int nb_exos;

    /*Chercher les différents exercices possibles et les mettre sous la forme d'une liste */
    printf("Bonjour, voici les differents exercices disponibles\n");
    nb_exos=comptageExercices(exos_dispos);
    printf("%d",nb_exos);
    return 0;

    /*Afficher les exos disponibles sous la forme -maths debutant tapez A*/


}
