#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>

void lectureFichier(FILE * fichier, S_question questions[], int i){
    int c; //Char
    char array[100] = "";

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
