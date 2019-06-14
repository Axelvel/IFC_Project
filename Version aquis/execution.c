#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#include "systemeExploitation.h"
#include "struct.h"
#include "buffer.h"
#include "inscription.h"

void execution(S_question questions[],int nb_question,int mode)
{
    //VARIABLES
    int nb_tentatives,points=0,totalpoints=0,j=0;
    char nom_fichier_resultat[100]="ResultatsEleves/Resultats - ",nom_eleve[100],reponse[50];
     //Variables de timer
    time_t temps_initial, temps_ecoule;

    //DEBUT

    ////ON POSE LES QUESTIONS UNES PAR UNE. SI ON A BON ON PASSE A CELLE DAPRES, SINON CA SE REPETE(a ameliorer pour mode examen et entrainement cc matteo)

    temps_initial = time(NULL);

    if(mode==0)
    {
        for(j=0; j<nb_question; j++)
        {
            NETTOYER();
            nb_tentatives=0;
            do
            {
                if (nb_tentatives!=0)
                {
                    printf("\nFaux ! Plus que %d essai(s) !\n\n", 3-nb_tentatives);
                }
                printf("--- Question %d/%d : \n", j+1, nb_question);
                printf("\n%s",questions[j].enonce);
                printf("\nnombre de points : %i", questions[j].points);
                printf("\n\nEntrez votre reponse : ");
                gets(reponse);
                nb_tentatives++;
            }
            while(stricmp(reponse,questions[j].solution)!=0 && nb_tentatives != 3);
            if (stricmp(reponse,questions[j].solution)!=0)
            {
                printf("\nFaux, la solution etait %s\n\n",questions[j].solution);
                getch();
            }

        }
    }
    else
    {
        inscription(nom_eleve);
        NETTOYER();

        //On cree le fichier au nom de l'élève et on le remplit petit à petit
        strcat(nom_fichier_resultat,nom_eleve);
        strcat(nom_fichier_resultat,".txt");
        FILE* fichier_resultat= fopen(nom_fichier_resultat, "a");

        fprintf(fichier_resultat,"Résultats de l'eleve %s:\n",nom_eleve);

        for(j=0; j<nb_question; j++)
        {
            NETTOYER();
            printf("--- Question %d/%d : \n", j+1, nb_question);
            printf("\n%s",questions[j].enonce);
            printf("\nnombre de points : %i", questions[j].points);
            printf("\n\nEntrez votre reponse :");
            gets(reponse);
            totalpoints=totalpoints + questions[j].points;
            system("cls");
            if(stricmp(reponse,questions[j].solution)==0)
            {
                points = points + questions[j].points;
            }

            fprintf(fichier_resultat,"%i) Reponse attendue : %s -- Réponse donnee : %s\n",j,questions[j].solution,reponse);


        }
        fprintf(fichier_resultat,"\nNote : %i/%i",points,totalpoints);

        temps_ecoule = time(NULL);

        printf("Vous avez mis %f secondes pour finir cet exercice !", difftime(temps_ecoule, temps_initial));
        fprintf(fichier_resultat,"\n\nL'eleve a mit %f secondes pour finir l'exercice",difftime(temps_ecoule,temps_initial));

        fclose(fichier_resultat);
    }
}
