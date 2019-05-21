#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

void execution(S_question questions[],int nb_question)
{

    int reponse; //reponse de l'utilisateur
    int j=0;
   // int note; //servira à compter les points

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
}
