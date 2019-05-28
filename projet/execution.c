#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "buffer.h"


void execution(S_question questions[],int nb_question,int mode)
{

    int reponse; //reponse de l'utilisateur
    int j=0;
    int points=0;
    int totalpoints=0;
    int nb_tentatives;
    char nom_fichier_resultat[100]="ResultatsEleves/Resultats - ";
    char nom_eleve[100];
   // int note; //servira à compter les points

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
                system("cls");

                }
                while(reponse!=questions[j].solution && nb_tentatives!=3);
                printf("La solution etait %i",questions[j].solution);

            }
    }
    else
    {
        printf("Entrez votre nom et prénom sous ce format : NOM-PRENOM\n");
        viderBuffer();
        gets(nom_eleve);
        system("cls");

        //On cree le fichier au nom de l'élève
        strcat(nom_fichier_resultat,nom_eleve);
        strcat(nom_fichier_resultat,".txt");
        FILE* fichier_resultat= fopen(nom_fichier_resultat, "a");

        fprintf(fichier_resultat,"Résultats de l'élève NOM :\n");

        for(j=0;j<nb_question;j++)
            {

                        printf("--- Question %d/%d : \n", j+1, nb_question);
                        printf("\n%s",questions[j].enonce);
                        printf("SolutioNn : %i", questions[j].solution);
                        printf("\nnombre de points : %i", questions[j].points);
                        printf("\n\nEntrez votre reponse :");
                        scanf("%i",&reponse);
                        totalpoints=totalpoints + questions[j].points;
                        system("cls");
                        if(reponse==questions[j].solution)
                        {
                            points = points + questions[j].points;
                        }

                        fprintf(fichier_resultat,"%i) Réponse attendue : %i -- Réponse donnée : %i\n",j,questions[j].solution,reponse);

            }
            fprintf(fichier_resultat,"\nNote : %i/%i",points,totalpoints);
        fclose(fichier_resultat);
    }
}
