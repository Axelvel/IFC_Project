#include <stdio.h>
#include <stdlib.h>

/* Fonction pour vider le buffer */

void viderBuffer()
{
    //VARIABLES
    int c = 0;

    //DEBUT
    while (c != '\n' && c != EOF)
        {
        c = getchar();
        }
}
