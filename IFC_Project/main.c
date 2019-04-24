#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "saisie.h"


int main() {

    char array[100] = "";
    FILE* fichier = NULL;
    fichier = fopen("./IFC_Project/fichier.txt", "r+");

    if (fichier != NULL){

        fgets(array,50,fichier);
        printf("%s\n", array);

        //Position du curseur
        printf("position du curseur : %ld",ftell(fichier));
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


