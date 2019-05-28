#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comptageExercices.h"
#include "struct.h"
#include "nbQuestions.h"
#include "execution.h"
#include "lectureFichier.h"
#include "cherche_exercice.h"

int menu()
{
    char nomFichier[20];
    FILE* fichier = NULL;
    int nb_exos;
    int choix;
    int nb_question;
    int mode = 0;
    int i =0;
    long pos_cur = 0; //position du curseur

    /*Chercher les différents exercices possibles et les mettre sous la forme d'une liste */
    char exos_dispos[50][25];
    nb_exos=cherche_exercice(exos_dispos);
    //printf("%d",nb_exos);
    //On choisit l'exercice
    printf("\nBonjour, voici les differents exercices disponibles\n");
    for(int i=0;i<nb_exos;i++)
    {
        printf("\n%i -- %s",i,exos_dispos[i]);
    }
    printf("\n\nAppuyez sur la touche correspondante a l'exercice voulu : ");
    scanf("%i",&choix);

    strcat(nomFichier,exos_dispos[choix]);

    /*Afficher les exos disponibles sous la forme -maths debutant tapez A*/

    printf("\nVous avez choisi : %s",nomFichier);
    strcat(nomFichier,".txt");

    fichier = fopen(nomFichier, "r+");
    nb_question = nombreQuestions(fichier);
    printf("\nIl y a %d questions dans cet exercice \n\n", nombreQuestions(fichier));

        ////ON CREE LE TABLEAU DE STRUCTURE
    S_question questions[nb_question];

        ////ON ENREGISTRE TOUTES LES DONNES DANS LE TABLEAU DE STRUCTURE(ICI J'AI EGALEMENT FAIS EN SORTE DE TOUT AFFICHER POUR VERIFIER MAIS ON ENLEVERA CA APRES)
    do {

        fseek(fichier, pos_cur, SEEK_SET);
        fscanf(fichier, "@%i %i", &questions[i].solution, &questions[i].points);
        lectureFichier(fichier,questions,i);
        pos_cur = ftell(fichier);
        i++;
            }
    while (i < nb_question);

    printf("Entrez 0 pour le mode entrainement et 1 pour le mode examen");
    scanf("%i,&mode);
    execution(questions,nb_question,mode);


    fclose(fichier);

}
