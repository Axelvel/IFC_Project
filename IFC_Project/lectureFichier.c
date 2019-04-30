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

     printf("\n");

    while ((c = getc(fichier)) != '@' && c != EOF) {

       // if ((c = getc(fichier)) == '@') {

          //  printf("\n***Position du curseur : %ld \n",ftell(fichier));
         //   fseek(fichier, -1, SEEK_CUR);
         //   printf("\n***Position du curseur : %ld \n",ftell(fichier));

        //}

    }
    fseek(fichier, -1, SEEK_CUR);

}
