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

    int i = 0;
    int j = 0;
    long pos_cur = 0; //position du curseur

    int reponse; //reponse de l'utilisateur



    if (fichier != NULL){
            ////CALCUL NOMBRE DE QUESTIONS////
        int nb_question = nombreQuestions(fichier);
        printf("\nIl y a %d questions dans cet exercice \n\n", nombreQuestions(fichier));

        ////ON CREER LE TABLEAU DE STRUCTURE
         S_question questions[nb_question];

        ////ON ENREGISTRE TOUTES LES DONNES DANS LE TABLEAU DE STRUCTURE(ICI J'AI EGALEMENT FAIS EN SORTE DE TOUT AFFICHER POUR VERIFIER MAIS ON ENLEVERA CA APRES)
         do {

                fseek(fichier, pos_cur, SEEK_SET);
                fscanf(fichier, "@%i %i", &questions[i].solution, &questions[i].points);
                lectureFichier(fichier,questions,i);
                pos_cur = ftell(fichier);
                i++;
            } while (i < nb_question);
        ////ON POSE LES QUESTIONS UNES PAR UNE. SI ON A BON ON PASSE A CELLE DAPRES, SINON CA SE REPETE(a ameliorer pour mode examen et entrainement cc matteo)
            for(j=0;j<nb_question;j++)
            {
                do{
                printf("--- Question %d/%d : \n", j+1, nb_question);
                printf("\n%s",questions[j].enonce);
                printf("SolutioNn : %i", questions[j].solution);
                printf("\nnombre de points : %i", questions[j].points);
                printf("\n\nEntrez votre reponse :");
                scanf("%i",&reponse);

                }
                while(reponse!=questions[j].solution);

            }


        fclose(fichier);
    } else {

    printf("\n\nErreur, le fichier texte n'a pas ete ouvert \n");
    }


}


