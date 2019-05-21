#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "choixFichier.h"
#include "struct.h"
#include "nbQuestions.h"
#include "saisie.h"
#include "execution.h"
#include "lectureFichier.h"





int main() {

        ////VARIABLES////
FILE* fichier = NULL;

    int i = 0;
    long pos_cur = 0; //position du curseur
    char nomFichier[20]="";

    choixFichier(nomFichier);

    fichier = fopen(nomFichier, "r+");


    if (fichier != NULL){
            ////CALCUL NOMBRE DE QUESTIONS////
        int nb_question = nombreQuestions(fichier);
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
            } while (i < nb_question);

        execution(questions,nb_question);


        fclose(fichier);
    } else {

    printf("\n\nErreur, le fichier texte n'a pas ete ouvert \n");
    }


}


