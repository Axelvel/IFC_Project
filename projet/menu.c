#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comptageExercices.h"

void menu(char * nomFichier)
{
    char toutfichier[100][25];

    int nb_exos;
    int i;
    int j = 0;
    int choix;

    /*Chercher les différents exercices possibles et les mettre sous la forme d'une liste */
    nb_exos=comptageExercices(toutfichier);
    char exos_dispos[nb_exos][25];
    //printf("%d",nb_exos);

    //On récupère uniquement les fichiers texte dans le tableau exos_dispos
    for(i=0;i<100;i++)
    {
        if((strcmp(&toutfichier[i][strlen(toutfichier[i])-3],"txt")==0)&&(strcmp(toutfichier[i],"resultat.txt")!=0))
        {
            strncpy(exos_dispos[j],toutfichier[i],strlen(toutfichier[i])-4);
            exos_dispos[j][strlen(toutfichier[i])-4]='\0';
            j++;
        }
    }
    //On choisit l'exercice
    printf("Bonjour, voici les differents exercices disponibles\n");
    for(i=0;i<j;i++)
    {
        printf("\n%i -- %s",i,exos_dispos[i]);
    }
    printf("\nAppuyez sur la touche correspondante à l'exercice voulu");
    scanf("%i",&choix);

    strcat(nomFichier,exos_dispos[choix]);
    strcat(nomFichier,".txt");

    /*Afficher les exos disponibles sous la forme -maths debutant tapez A*/
}
