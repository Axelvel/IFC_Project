#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

void lectureFichier(FILE * fichier, S_question questions[], int i){

   //VARIABLES
    int c; //Char
    char array[100] = "";

    //DEBUT
    while ((c = getc(fichier)) != '#' && c != EOF){
            fseek(fichier, -1, SEEK_CUR);
            fgets(array,100,fichier);
          //  printf("%s", array);
        }

        strcpy(questions[i].enonce,array);


    //Permet de retourner jusqu'au @ suivant, puis on recule de 1
   while ((c = getc(fichier)) != '@' && c != EOF) {
    }
    fseek(fichier, -1, SEEK_CUR);

}
