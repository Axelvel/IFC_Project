#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

void execution(S_question questions[],int nb_question,int mode)
{

    int reponse; //reponse de l'utilisateur
    int j=0;
   // int note; //servira à compter les points
    int nb_tentatives;
    ////ON POSE LES QUESTIONS UNES PAR UNE. SI ON A BON ON PASSE A CELLE DAPRES, SINON CA SE REPETE(a ameliorer pour mode examen et entrainement cc matteo)
    if(mode==0)
    {
        for(j=0;j<nb_question;j++)
            {
                    nb_tentatives=0;
                    do{
                        printf("--- Question %d/%d : \n", j+1, nb_question);
                        printf("\n%s",questions[j].enonce);
                        printf("SolutioNn : %i", questions[j].solution);
                        printf("\nnombre de points : %i", questions[j].points);
                        printf("\n\nEntrez votre reponse :");
                        scanf("%i",&reponse);
                        nb_tentatives++;

                        }
                    while(reponse!=questions[j].solution && nb_tentatives!=3);

                    printf("La solution etait %i",questions[j].solution);

            }
    }
    else
    {
        FILE* fichier_resultat= fopen("resultat.txt", "a");
        for(j=0;j<nb_question;j++)
            {

                        printf("--- Question %d/%d : \n", j+1, nb_question);
                        printf("\n%s",questions[j].enonce);
                        printf("SolutioNn : %i", questions[j].solution);
                        printf("\nnombre de points : %i", questions[j].points);
                        printf("\n\nEntrez votre reponse :");
                        scanf("%i",&reponse);
                        fprintf(fichier_resultat,"%i) %i\n",j,reponse);


            }
        fclose(fichier_resultat);
    }
}
