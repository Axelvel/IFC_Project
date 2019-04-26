#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "saisie.h"
#include "lectureFichier.h"


int main() {

    //char array[100] = "";
    FILE* fichier = NULL;
    fichier = fopen("./IFC_Project/fichier.txt", "r+");
  //  int c;

    if (fichier != NULL){

            lectureFichier(fichier);

            lectureFichier(fichier);

       /* while ((c = getc(fichier)) != '#' && c != EOF){
            fseek(fichier, -1, SEEK_CUR);
            fgets(array,100,fichier);
            printf("%s", array);
        }

        while ((c = getc(fichier)) != '#' && c != EOF){
            fseek(fichier, -1, SEEK_CUR);
            fgets(array,100,fichier);
            printf("%s", array);
        }

        */


        //Position du curseur
        printf("\nposition du curseur : %ld \n",ftell(fichier));
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


