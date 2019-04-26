#include <stdio.h>
#include <stdlib.h>

void lectureFichier(FILE * fichier){
    int c;
    char array[100] = "";

    while ((c = getc(fichier)) != '#' && c != EOF){
            fseek(fichier, -1, SEEK_CUR);
            fgets(array,100,fichier);
            printf("%s", array);
        }

}
