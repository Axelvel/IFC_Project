#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "comptageExercices.h"
#include "menu.h"
#include "struct.h"
#include "nbQuestions.h"
#include "saisie.h"
#include "execution.h"
#include "lectureFichier.h"
#include "buffer.h"

int main() {

        ////VARIABLES////
FILE* fichier = NULL;

    int i = 0;
    int mode = 1;
    long pos_cur = 0; //position du curseur
    char nomFichier[40]="";


    menu(nomFichier);
    system("cls");

    fichier = fopen(nomFichier, "r+");


    if (fichier != NULL){
            ////CALCUL NOMBRE DE QUESTIONS////
        int nb_question = nombreQuestions(fichier);

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

        execution(questions,nb_question,mode);


        fclose(fichier);
    } else {

    printf("\n\nErreur, le fichier texte n'a pas ete ouvert \n");
    }


}


