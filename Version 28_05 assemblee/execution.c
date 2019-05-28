#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

void execution(S_question questions[],int nb_question,int mode)
{

    int reponse; //reponse de l'utilisateur
    int j=0;
    int nb_tentatives;
   // int note; //servira à compter les points

    ////ON POSE LES QUESTIONS UNES PAR UNE. SI ON A BON ON PASSE A CELLE DAPRES, SINON CA SE REPETE(a ameliorer pour mode examen et entrainement cc matteo)

    
    //Variables de timer
    time_t temps_initial, temps_ecoule;

    temps_initial = time(NULL);
    
    
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
                printf("\n\nEntrez votre reponse : ");
                scanf("%i",&reponse);
                nb_tentatives++;

                if(reponse!=questions[j].solution && nb_tentatives != 3){
                    printf("\nFaux ! Plus que %d essai(s) !\n\n", 3-nb_tentatives);
                }


                }
                while(reponse!=questions[j].solution && nb_tentatives!=3);

                if (reponse!=questions[j].solution){
                    printf("\nFaux, la solution etait %i\n\n",questions[j].solution);
                }

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
                        printf("\n\nEntrez votre reponse : ");
                        scanf("%i",&reponse);
                        fprintf(fichier_resultat,"%i) %i\n",j,reponse);


            }
        fclose(fichier_resultat);
        
         temps_ecoule = time(NULL);

        printf("Vous avez mit %f secondes pour resoudre cet exercice !", difftime(temps_ecoule, temps_initial));
    }
}
