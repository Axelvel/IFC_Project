#include <stdio.h>
#include <stdlib.h>

int nombreQuestions (FILE * fichier){
    //VARIABLES
    int nb_de_questions = 0,c;

    //DEBUT
    while ((c = getc(fichier)) != EOF){
            if (c == '@') {
                nb_de_questions++;
            }
        }

    rewind(fichier);
    return nb_de_questions;

}
