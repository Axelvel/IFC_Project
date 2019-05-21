#include <stdio.h>
#include <stdlib.h>

void lectureFichier(FILE * fichier){
    int c; //Char
    char array[100] = "";

    while ((c = getc(fichier)) != '#' && c != EOF){
            fseek(fichier, -1, SEEK_CUR);
            fgets(array,100,fichier);
            printf("%s", array);
        }

     printf("\n\n\n");
    //Permet de retourner jusqu'au @ suivant, puis on recule de 1
   while ((c = getc(fichier)) != '@' && c != EOF) {
    }
    fseek(fichier, -1, SEEK_CUR);

}
