#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#include <string.h>

void Creation_exercice()
{
    int nb_questions,nb_pts;
    char nom_fichier[100],solution[100],intitule[100];
    printf("\nComment voulez vous appeler votre test?");
    gets(nom_fichier);
    strcat(nom_fichier,".txt");         /* Cette partie cree le fichier avec son nom et son type */
    FILE* fichier_test= fopen(nom_fichier, "w");
    do
    {
        printf("\nCombien de questions voulez-vous dans le test? ");
        scanf("%d",&nb_questions);
        viderBuffer();
    }
    while(nb_questions<0);

    for(int k=0;k<nb_questions;k++)
    {
        printf("\n----------Question %d/%d----------",k+1,nb_questions);
        printf("\nQuel est l'intitule de la question? ");
        gets(intitule);
        printf("\nQuelle est la solution a la question?");
        gets(solution);
        enlever_les_espaces(solution);
        printf("\nDonnez le nombre de points de cette question? ");
        scanf("%d",&nb_pts);
        viderBuffer();
        fprintf(fichier_test,"@%s %d\n%s\n#\n\n",solution,nb_pts,intitule);
    }
    printf("\nVotre test a ete cree, retour au menu");
    fclose(fichier_test);

}
