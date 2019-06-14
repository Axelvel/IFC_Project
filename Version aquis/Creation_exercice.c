#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "buffer.h"
#include "verifNumeric.h"


void Creation_exercice()
{
    //VARIABLES
    char nbPts[100];
    int nb_pts;
    char nb_questions[100];
    int nbQuestions;

    char nom_fichier[100],solution[100],intitule[100];

    //DEBUT

    printf("\nComment voulez vous appeler votre test?");
    gets(nom_fichier);

    strcat(nom_fichier,".txt");         /* Cette partie cree le fichier avec son nom et son type */
    FILE* fichier_test= fopen(nom_fichier, "w");
    do
    {
        printf("\nCombien de questions voulez-vous dans le test? ");
        gets(nb_questions);
    }
    while(verifNumeric(nb_questions));
    nbQuestions=atoi(nb_questions);

    for(int k=0;k<nbQuestions;k++)
    {
        printf("\n----------Question %d/%d----------",k+1,nbQuestions);
        printf("\nQuel est l'intitule de la question? ");
        gets(intitule);
        printf("\nQuelle est la solution a la question? !!! Les solutions ne peuvent pas contenir d'espaces !!! ");
        gets(solution);

        do{
                do{
                printf("\nDonnez le nombre de points de cette question? ");
                gets(nbPts);
                }while(verifNumeric(nbPts));

            nb_pts=atoi(nbPts);
        }
        while(nb_pts<=0);

        fprintf(fichier_test,"@%s %d\n%s\n#\n\n",solution,nb_pts,intitule);
    }
    printf("\nVotre test a ete cree. Retour au menu");
    fclose(fichier_test);

}
