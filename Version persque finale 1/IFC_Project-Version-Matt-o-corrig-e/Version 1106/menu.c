#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "systemeExploitation.h"
#include "struct.h"
#include "nbQuestions.h"
#include "execution.h"
#include "lectureFichier.h"
#include "cherche_exercice.h"
#include "buffer.h"

int menu()
{
    char nomFichier[40]="";
    FILE* fichier = NULL;
    int nb_exos;
    int choix;
    int nb_question;
    int mode;
    int compteur=0;
    char choix_sortie;

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
            printf("\nAppuyez sur la touche correspondante a l'exercice voulu ");
            scanf("%i",&choix);
            viderBuffer();
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
        fscanf(fichier, "@%s %i", questions[compteur].solution, &questions[compteur].points);
        lectureFichier(fichier,questions,compteur);
        pos_cur = ftell(fichier);
        compteur++;
            }
    while (compteur < nb_question);

    do
    {
        printf("Voulez-vous l'ouvrir en mode entrainement ou examen?\n 0 pour entrainement\n 1 pour examen\n");
        scanf("%d",&mode);
        viderBuffer();
    }
    while (mode!=1 && mode!=0);
    NETTOYER();
    execution(questions,nb_question,mode);
    fclose(fichier);

    do
    {
        printf("\nVoulez-vous quitter l'application? Rentrez O pour OUI et N pour NON  ");
        scanf("%c",&choix_sortie);
        viderBuffer();
    }
    while(choix_sortie!='O'&&choix_sortie!='N');
    NETTOYER();
    if (choix_sortie=='O')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
