#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "saisie.h"
#include "lectureFichier.h"
#include "nbQuestions.h"


int main() {

        ////VARIABLES////
    FILE* fichier = NULL;
    fichier = fopen("./fichier.txt", "r+");

    int sol; //solution des questions
    int pts; //points attribués aux questions

    int i = 1;
    long pos_cur = 0; //position du curseur

    int reponse; //reponse de l'utilisateur

    if (fichier != NULL){
            ////CALCUL NOMBRE DE QUESTIONS////
        int nb_question = nombreQuestions(fichier);
        printf("\nIl y a %d questions dans cet exercice \n\n", nombreQuestions(fichier));

            ////AFFICHAGE DE TOUTES LES QUESTIONS////
        do{
                do {

                printf("Question %d/%d : \n\n", i, nb_question);
                fseek(fichier, pos_cur, SEEK_SET);
                fscanf(fichier, "@%d %d", &sol, &pts);
                printf("solution : %d\n", sol);
                printf("nombre de points : %d\n", pts);
                lectureFichier(fichier);
                pos_cur = ftell(fichier);

                printf("\nEntrez votre réponse, puis appuyez sur entrée :");
                scanf("%i",&reponse);

                //Message d'erreur ou de réussite
                if(reponse!=sol)
                    {
                        printf("Mauvaise reponse\n");
                    }
                    else
                    {
                        printf("ok\n");
                    }

                }while(reponse!=sol);

                i++;
                //NOTE : mettre toutes les questions dans des structures, afin que l'on puisse ensuite les utiliser librement sans avoir à se soucier du curseur

        } while (i < nb_question +1);


        fclose(fichier);
    } else {

    printf("\n\nErreur, le fichier texte n'a pas ete ouvert \n");
    }


}


