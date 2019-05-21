#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "saisie.h"
#include "lectureFichier.h"
#include "nbQuestions.h"



int main() {

        ////VARIABLES////
    FILE* fichier = NULL;
    fichier = fopen("./fichier.txt", "r+");

    //int sol; //solution des questions
    //int pts; //points attribués aux questions

    int i = 0;
    long pos_cur = 0; //position du curseur

    //int reponse; //reponse de l'utilisateur



    if (fichier != NULL){
            ////CALCUL NOMBRE DE QUESTIONS////
        int nb_question = nombreQuestions(fichier);
        printf("\nIl y a %d questions dans cet exercice \n\n", nombreQuestions(fichier));

        ////ON CREER LE TABLEAU DE STRUCTURE
         S_question questions[nb_question];

        ////ON ENREGISTRE TOUTES LES DONNES DANS LE TABLEAU DE STRUCTURE(ICI J'AI EGALEMENT FAIS EN SORTE DE TOUT AFFICHER POUR VERIFIER MAIS ON ENLEVERA CA APRES)
         do {

                printf("Question %d/%d : \n\n", i+1, nb_question);
                fseek(fichier, pos_cur, SEEK_SET);
                fscanf(fichier, "@%i %i", &questions[i].solution, &questions[i].points);
                printf("solution : %i\n", questions[i].solution);
                printf("nombre de points : %i\n", questions[i].points);
                lectureFichier(fichier,questions,i);
                printf("%s",questions[i].enonce);
                pos_cur = ftell(fichier);
                i++;
                } while (i < nb_question);

        fclose(fichier);
    } else {

    printf("\n\nErreur, le fichier texte n'a pas ete ouvert \n");
    }


}


