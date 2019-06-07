#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "couleurs.h"
#include "buffer.h"
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
    int mode;
    int compteur=0;
    char choix_sortie;

    long pos_cur = 0; //position du curseur

    /*Chercher les différents exercices possibles et les mettre sous la forme d'une liste */
    char exos_dispos[50][25];
    nb_exos=cherche_exercice(exos_dispos);

    //On affiche les différents exercices disponibles et l'utilisateur choisit celui qu'il veut executer
    Color(12,0);
    printf("\nBonjour ! Voici les differents exercices disponibles\n");
    Color(15,0);
    for(int i=0;i<nb_exos;i++)
    {
        printf("\n%i -- %s",i,exos_dispos[i]);
    }
    do{
            Color(12,0);
            printf("\nAppuyez sur la touche correspondante a l'exercice voulu, puis appuyez sur entrer.");
        scanf("%i",&choix);
    Color(15,0);
    }
    while(choix>=nb_exos);
    NETTOYER();
    strcat(nomFichier,exos_dispos[choix]);
    Color(12,0);
    printf("\nVous avez choisi : %s",nomFichier);
    Color(15,0);
    strcat(nomFichier,".txt");

    //On ouvre l'exercice voulu, et on compte le nombre de questions
    fichier = fopen(nomFichier, "r+");
    nb_question = nombreQuestions(fichier);
    Color(12,0);
    printf("\nIl y a %d questions dans cet exercice \n\n", nombreQuestions(fichier));
    Color(15,0);

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


    //On choisit examen entrainement
    do
    {
    printf("Voulez-vous l'ouvrir en mode entrainement ou examen?\n 0 -- Entrainement\n 1 -- Examen\n");
    scanf("%d",&mode);
    viderBuffer();
    }
    while (mode!=1 && mode!=0);
    NETTOYER();
    execution(questions,nb_question,mode);
    fclose(fichier);

    //On propose de recommencer
     do
    {
        printf("\nVoulez-vous quitter l'application? Rentrez O pour OUI et N pour NON  ");
        scanf("%s",&choix_sortie);
        viderBuffer();
    }
    while((choix_sortie!='O')&&(choix_sortie!='N'));

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
