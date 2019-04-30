#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "saisie.h"
#include "lectureFichier.h"
#include "nbQuestions.h"


int main() {

    //char array[100] = "";
    FILE* fichier = NULL;
    fichier = fopen("./IFC_Project/fichier.txt", "r+");
    int sol;
    int pts;
  //  int c;
  int i = 1;


  long pos_cur = 0;

    if (fichier != NULL){
            int nb_question = nombreQuestions(fichier);

            printf("Il y a %d questions dans cet exercice \n\n", nombreQuestions(fichier));


      //  for (int i = 0; i < nombreQuestions(fichier)+ 1; i++) {
do {

        printf("Question #%d \n", i);
            fseek(fichier, pos_cur, SEEK_SET);
            fscanf(fichier, "@%d %d", &sol, &pts);
            printf("solution : %d\n", sol);
            printf("nombre de points : %d\n", pts);
            lectureFichier(fichier);
            pos_cur = ftell(fichier);
            //printf("\n*Position du curseur : %ld \n",ftell(fichier));
            i++;

} while (i < nb_question +1);
      //  }




           /* fscanf(fichier, "@%d %d", &sol, &pts);
           // printf("\nPosition du curseur : %ld \n",ftell(fichier));
            printf("solution : %d\n", sol);
            printf("nombre de points : %d\n", pts);
            lectureFichier(fichier);


            fscanf(fichier, "@%d %d", &sol, &pts);
            printf("solution : %d\n", sol);
            printf("nombre de points : %d\n", pts);
            lectureFichier(fichier); */


        fclose(fichier);
    } else {

    printf("\n\nErreur, le fichier texte n'a pas ete ouvert \n");
    }

  /*  char rep;
    printf("Quelle matiere voulez vous reviser ? \n");
    rep = saisie();
    printf("%c\n", rep);
    return 0;
*/
}


