#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "systemeExploitation.h"
#include "struct.h"
#include "nbQuestions.h"
#include "execution.h"
#include "lectureFichier.h"
#include "cherche_exercice.h"

int menu()
{
    char nomFichier[40]="";
    FILE* fichier = NULL;
    int nb_exos;
    int choix;
    int nb_question;
    int mode = 1;
    int compteur=0;

    long pos_cur = 0; //position du curseur

    /*Chercher les différents exercices possibles et les mettre sous la forme d'une liste */
    char exos_dispos[50][25];
    nb_exos=cherche_exercice(exos_dispos);

    //On affiche les différents exercices disponibles et l'utilisateur choisit celui qu'il veut executer
    printf("\nBonjour, voici les differents exercices disponibles\n");
    for(int i=0;i<nb_exos;i++)
    {
        printf("\n%i -- %s",i,exos_dispos[i]);
    }
    do{
            printf("\nAppuyez sur la touche correspondante à l'exercice voulu");
        scanf("%i",&choix);
    }
    while(choix>=nb_exos);
    NETTOYER();
    strcat(nomFichier,exos_dispos[choix]);
    printf("\nVous avez choisi : %s",nomFichier);
    strcat(nomFichier,".txt");

    //On ouvre l'exercice voulu, et on compte le nombre de questions
    fichier = fopen(nomFichier, "r+");
    nb_question = nombreQuestions(fichier);
    printf("\nIl y a %d questions dans cet exercice \n\n", nombreQuestions(fichier));

        ////ON CREE LE TABLEAU DE STRUCTURE
    S_question questions[nb_question];

        ////ON ENREGISTRE TOUTES LES DONNES DANS LE TABLEAU DE STRUCTURE
    do {
        fseek(fichier, pos_cur, SEEK_SET);
        fscanf(fichier, "@%i %i", &questions[compteur].solution, &questions[compteur].points);
        lectureFichier(fichier,questions,compteur);
        pos_cur = ftell(fichier);
        compteur++;
            }
    while (compteur < nb_question);

    execution(questions,nb_question,mode);


    fclose(fichier);

}
